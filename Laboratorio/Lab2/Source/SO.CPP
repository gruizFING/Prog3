/* 4317743 */

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <assert.h>
#include <ctype.h>

#include "so.h"

#define Tam_Hash 229

using namespace std;


typedef enum Estado {listo,bloqueado,corriendo} Estado;

typedef struct AVLProg {
	char* nomProg;
	char* code;
	int FB;
	AVLProg* izq;
	AVLProg* der;
} AVLProg;

typedef struct RProc {
	char rec;
	RProc* sig;
	RProc* ant;
} RProc;

typedef struct ColaRq {
	RProc* princ;
	RProc* final;
} ColaRq;

typedef struct NHash NHash;
typedef struct NRec NRec;
typedef struct CPU CPU;
typedef struct Proc {
	unsigned int inst;
	unsigned int Pid;
	ColaRq* RQTiene;
	char  RQEspera;
	AVLProg* Pprog;
	NHash* Phash;
	unsigned int Idcpu;
	NRec* Prec;
	Estado est;
	Proc* sig;
	Proc* ant;
} Proc;


typedef struct NRec {
	Proc* proc;
	NRec* sig;
	NRec* ant;
} NRec;

typedef struct Recurso {
	Proc* duenio;
	RProc* rproc;
	NRec* princ;
	NRec* final;
} Recurso;
	
typedef struct NHash {
	Proc* proc;
	NHash* sig;
	NHash* ant;
} NHash;
	
typedef struct HProc {
	NHash* CHash[Tam_Hash];
	unsigned int cantProc;
} HProc;

typedef struct ColaProc {
	Proc* princ;
	Proc* final;
} ColaProc;

		
typedef struct SO {
	Proc** cpu;
	AVLProg* progs;
	HProc* Hash;
	ColaProc* Listos;
	ColaProc* Bloq;
	Recurso* RSo; 
	unsigned int maxcpus;
} SO;



struct SO* iniciar_SO(unsigned int maxcpus) {
	if (maxcpus == 0)
		return NULL;
	else
	{
		SO* so = new SO;
		so->cpu = new Proc*[maxcpus];
		so->maxcpus = maxcpus;
		for (unsigned int i = 0;i < maxcpus;i++)
			so->cpu[i] = NULL;
		so->progs = NULL;
		so->Hash = new HProc;
		so->Hash->cantProc = 0;
		for (unsigned int i = 0;i < Tam_Hash;i++)
			so->Hash->CHash[i] = NULL;
		so->Listos = new ColaProc;
		so->Listos->princ = NULL;
		so->Listos->final = NULL;
		so->Bloq = new ColaProc;
		so->Bloq->princ = NULL;
		so->Bloq->final = NULL;
		so->RSo = new Recurso[26];
		for (unsigned int i = 0;i < 26;i++)
		{
			so->RSo[i].duenio = NULL;
			so->RSo[i].rproc  = NULL;
			so->RSo[i].princ  = NULL;
			so->RSo[i].final  = NULL;
		}
		return so;
	}
}

/********Operaciones de Rebalanceo del AVLProg*************/

void RebalancearLL(AVLProg* &a) {
	AVLProg* nuevaraiz = a->izq;
	a->izq = nuevaraiz->der;
	nuevaraiz->der = a;
	a->FB = 0;
	nuevaraiz->FB = 0;
	a = nuevaraiz;
}

void RebalancearRR(AVLProg* &a) {
	AVLProg* nuevaraiz = a->der;
	a->der = nuevaraiz->izq;
	nuevaraiz->izq = a;
	a->FB = 0;
	nuevaraiz->FB = 0;
	a = nuevaraiz;
}

void RebalancearLR(AVLProg* &a) {
	int insizq;
	if (a->izq->der->FB == 1)
		insizq = 1;
	else if (a->izq->der->FB == -1)
		insizq = 0;
	else
		insizq = -1;
	RebalancearRR(a->izq);
	RebalancearLL(a);
	if (insizq == 1)
		a->der->FB = -1;
	else if (insizq == 0)
		a->izq->FB = 1;
}

void RebalancearRL(AVLProg* &a) {
	int insizq;
	if (a->der->izq->FB == 1)
		insizq = 1;
	else if (a->der->izq->FB == -1)
		insizq = 0;
	else
		insizq = -1;
	RebalancearLL(a->der);
	RebalancearRR(a);
	if (insizq == 1)
		a->der->FB = -1;
	else if (insizq == 0)
		a->izq->FB = 1;
}

/****************Operaciones del AVLProg******************/

/* Inserta el programa en el AVL de programas y devuelve true si hubo error */
bool InsertarProg(AVLProg* &prog,const char* nom,const char* codigo,bool &aumento) {
	if (prog == NULL) {
		prog = new AVLProg;
		prog->nomProg = new char[strlen(nom)+1];
		strcpy(prog->nomProg,nom);
		prog->code = new char[strlen(codigo)+1];
		strcpy(prog->code,codigo);
		prog->FB = 0;
		prog->izq = NULL;
		prog->der = NULL;
		aumento = true;
		return false;
	}
	else {
		if (strcmp(nom,prog->nomProg) < 0) { //Insertar a la izquierda
			bool error;
			error = InsertarProg(prog->izq,nom,codigo,aumento);
			if (error)
				return true;
			else if (aumento) 
			{
				switch (prog->FB) {
					case -1 :{
						prog->FB = 0;  //No se produce desbalanceo
						aumento = false;
						break;
					}
					case 0 :{
						prog->FB = 1; //Hay que mirar los ancestros
						break;
					}
					case 1 :{	//Rebalanceo, el tipo es LL o LR
						if (prog->izq->FB == 1) //Rebalanceo LL
							RebalancearLL(prog);
						else   //Rebalanceo LR
							RebalancearLR(prog);
						aumento = false;
						break;
					}
				}
			}
			return false;
		}
		else if (strcmp(nom,prog->nomProg) > 0) {  //Insertar a la derecha
			bool error;
			error = InsertarProg(prog->der,nom,codigo,aumento);
			if (error)
				return true;
			else if (aumento)
			{
				switch (prog->FB) {
					case 1 :{
						prog->FB = 0;  //No se produce desbalanceo
						aumento = false;
						break;
					}
					case 0 :{
						prog->FB = -1; //Hay que mirar los ancestros
						break;
					}
					case -1 :{	//Rebalanceo, el tipo es RR o RL
						if (prog->der->FB == -1) //Rebalanceo RR
							RebalancearRR(prog);
						else   //Rebalanceo RL
							RebalancearRL(prog);
						aumento = false;
						break;
					}
				}
			}
			return false;
		}
		else
			return true;
	}
}


//Imprime los nombres de los programas en la recorrida en orden del AVL.
//Operacion de orden O(A) peor caso, siendo A = cantProgs en el sistema.
void ImprimirEnOrden(AVLProg* a) {
	if (a != NULL) {
		if (a->izq == NULL)
		{
			cout << a->nomProg << endl;
			if (a->der != NULL)
				ImprimirEnOrden(a->der);
		}
		else
		{
			ImprimirEnOrden(a->izq);
			cout << a->nomProg << endl;
			if (a->der != NULL)
				ImprimirEnOrden(a->der);
				
		}
	}
}


//Busca el programa con nombre "nom" en el AVL y devuelve un puntero a el mismo.
//Si no lo encuentra devuelve false en "existe" y el puntero a NULL.
//Esta busqueda es de orden O(Log(A)) peor caso, con A = cantProgs en el sistema.
AVLProg* BuscarProg(AVLProg* a,const char* nom,bool &existe) {
	if (a == NULL)
	{
		existe = false;
		return NULL;
	}
	else if (strcmp(nom,a->nomProg) < 0)
		return (BuscarProg(a->izq,nom,existe));
	else if (strcmp(nom,a->nomProg) > 0)
		return (BuscarProg(a->der,nom,existe));
	else
	{
		existe = true;
		return a;
	}
}

//Libera la memoria reservada por el AVL de programas.
void DestruirAVLProg(AVLProg* ap) {
	if (ap != NULL)
	{
		DestruirAVLProg(ap->izq);
		DestruirAVLProg(ap->der);
		delete [] ap->nomProg;
		delete [] ap->code;
		delete ap;
		ap = NULL;
	}
}

			
/***************************************************************************/



int crearPrograma_SO(struct SO* so, const char* nombre, const char *codigo) {
	if ((strcmp(nombre,"") == 0) || (codigo[strlen(codigo)-1] != '@') || (so == NULL))   
		return SO_ERROR;
	else
	{
		bool error;
		bool aumento = false;
		error = InsertarProg(so->progs,nombre,codigo,aumento);
		if (error)
			return SO_ERROR;
		else
			return SO_OK;
	}
}

void imprimirProgramas_SO(struct SO* so) {
	cout << "Programas:\n";
	ImprimirEnOrden(so->progs);
}


/****************Operaciones de la Cola de Procesos****************/

void Encolar(ColaProc* q,Proc* p) {
	if (q->final == NULL)
	{
		q->princ = p;
		q->final = p;
		p->ant = NULL;
	}
	else
	{
		q->final->sig = p;
		p->ant = q->final;
		q->final = p;
	}
}

Proc* Desencolar(ColaProc* q) {
	if (q->princ == NULL)
		return NULL;
	else
	{
		Proc* proc = q->princ;
		q->princ = proc->sig;
		if (proc->sig == NULL)
			q->final = NULL;
		else
		{
			q->princ->ant = NULL;
			proc->sig = NULL;
		}
		return proc;
	}
}

//Pre: Cola 'q' no vacia.
//Saca el proceso 'p' de la cola 'q'.
void SacarProcC(ColaProc* q,Proc* p) {
	if (p == q->princ)
		Desencolar(q);
	else if (p == q->final)
	{
		q->final = q->final->ant;
		p->ant = NULL;
		q->final->sig = NULL;
	}
	else
	{
		p->ant->sig = p->sig;
		p->sig->ant = p->ant;
		p->sig = NULL;
		p->ant = NULL;
	}
}


/***************Operaciones de la Cola de los recursos del proceso***************/

RProc* EncolarRP(ColaRq* cr,char r) {
	RProc* nuevo = new RProc;
	nuevo->rec = r;
	nuevo->sig = NULL;
	if (cr->final == NULL)
	{
		cr->princ = nuevo;
		cr->final = nuevo;
		nuevo->ant = NULL;
	}
	else
	{
		cr->final->sig = nuevo;
		nuevo->ant = cr->final;
		cr->final = nuevo;
	}
	
	return nuevo;
}

void SacarRP(ColaRq* cr,RProc* pr) {
	if (pr == cr->princ)
	{
		cr->princ = cr->princ->sig;
		if (cr->princ == NULL)
			cr->final = NULL;
		else
			cr->princ->ant = NULL;
	}
	else if (pr == cr->final)
	{
		cr->final = cr->final->ant;
		if (cr->final == NULL)
			cr->princ = NULL;
		else
			cr->final->sig = NULL;
	}
	else
	{
		pr->ant->sig = pr->sig;
		pr->sig->ant = pr->ant;
	}
	
	delete pr;
}

/*******************Operaciones de la cola del recurso***************************/

NRec* EncolarRQ(Recurso &rq,Proc* p) {
	NRec* nuevo = new NRec;
	nuevo->proc = p;
	nuevo->sig = NULL;
	if (rq.final == NULL)
	{
		rq.princ = nuevo;
		rq.final = nuevo;
		nuevo->ant = NULL;
	}
	else
	{
		rq.final->sig = nuevo;
		nuevo->ant = rq.final;
		rq.final = nuevo;
	}
	
	return nuevo;
}

NRec* DesencolarRQ(Recurso &rq) {
	if (rq.princ == NULL)
		return NULL;
	else
	{
		NRec* prim = rq.princ;
		rq.princ = prim->sig;
		if (prim->sig == NULL)
			rq.final = NULL;
		else
		{
			rq.princ->ant = NULL;
			prim->sig = NULL;
		}
		return prim;
	}
}

void SacarRQ(Recurso &rq,NRec* nr) {
	if (nr == rq.princ)
		DesencolarRQ(rq);
	else if (nr == rq.final)
	{
		rq.final = rq.final->ant;
		if (rq.final == NULL)
			rq.princ = NULL;
		else
			rq.final->sig = NULL;
	}
	else
	{
		nr->ant->sig = nr->sig;
		nr->sig->ant = nr->ant;
	}
	delete nr;
}

/*************************************************************/

unsigned int ejecutar_SO(struct SO * so, const char* nombre) {
	bool existe = false;
	AVLProg* Pprog = BuscarProg(so->progs,nombre,existe);
	if (!existe)
		return 0;
	else
	{
		Proc* newProc = new Proc;
		newProc->inst = 1;
		newProc->RQTiene = new ColaRq;
		newProc->RQTiene->princ = NULL;
		newProc->RQTiene->final = NULL;
		newProc->Pprog = Pprog;
		newProc->est = listo;
		newProc->sig = NULL;
		newProc->Prec = NULL;
		
		//Lo inserto en la cola de los procesos listos.
		Encolar(so->Listos,newProc);
		
		//Agrego el proceso al Hash y actualizo la cantidad de procesos.
		so->Hash->cantProc++;
		newProc->Pid = so->Hash->cantProc;
		int lugar = ((newProc->Pid) % Tam_Hash);
		NHash* newCHash = new NHash;
		newCHash->proc = newProc;
		newCHash->sig = so->Hash->CHash[lugar];
		newCHash->ant = NULL;
		so->Hash->CHash[lugar] = newCHash;
		if (newCHash->sig != NULL)
			newCHash->sig->ant = newCHash;
		newProc->Phash = newCHash;
		
		return newProc->Pid;
	}
}


void imprimirProcesosBloqueados_SO(struct SO* so) {
	for (Proc* cpos = so->Bloq->princ;cpos != NULL;cpos = cpos->sig)
	{
		cout << "PID=" << cpos->Pid << " ";
		cout << "Archivo=" << cpos->Pprog->nomProg << ":" << cpos->inst << " ";
		cout << "Esperando=" << cpos->RQEspera << " ";
		cout << "Tiene=";
		for (RProc* r = cpos->RQTiene->princ;r != NULL;r = r->sig)
		{
			char c = r->rec; 
			cout << c;
			if (r->sig != NULL)
				cout << ",";
		}
		cout << endl;
	}
}


void imprimirProcesosListos_SO(struct SO* so) {
	for (Proc* cpos = so->Listos->princ;cpos != NULL;cpos = cpos->sig)
	{
		cout << "PID=" << cpos->Pid << " ";
		cout << "Archivo=" << cpos->Pprog->nomProg << ":" << cpos->inst << " ";
		cout << "Tiene=";
		for (RProc* r = cpos->RQTiene->princ;r != NULL;r = r->sig)
		{
			char c = r->rec; 
			cout << c;
			if (r->sig != NULL)
				cout << ",";
		}
		cout << endl;
	}
}
	
	
//Libera el recurso identificado por 'c' y se lo asigna al proceso correspondiente.
//Pre: El proceso 'p' es el dueño del recurso identificado por 'c'.
void LiberarRecurso(char c,Proc* p,SO* so) {
	int lugar = c - 'a';
	SacarRP(p->RQTiene,so->RSo[lugar].rproc);
	NRec* newDuenio = DesencolarRQ(so->RSo[lugar]);
	if (newDuenio != NULL)
	{
		so->RSo[lugar].duenio = newDuenio->proc;
		so->RSo[lugar].rproc = EncolarRP(newDuenio->proc->RQTiene,c);
		newDuenio->proc->Prec = NULL;
		newDuenio->proc->est = listo;
		SacarProcC(so->Bloq,newDuenio->proc);
		Encolar(so->Listos,newDuenio->proc);
		delete newDuenio;
	}
	else
	{
		so->RSo[lugar].duenio = NULL;
		so->RSo[lugar].rproc = NULL;
	}
}

//Libera todos los recursos asignados a el proceso 'p'.
void LiberarRecursos(Proc* p,SO* so) {
	for (RProc* r = p->RQTiene->princ;r != NULL;r = p->RQTiene->princ)
		LiberarRecurso(r->rec,p,so);
}

//Elimina el nodo de enganche del proceso en el hash.
void SacarPHash(NHash* &ini,NHash* aBorrar) {
	if (aBorrar == ini)
	{
		ini = aBorrar->sig;
		if (ini != NULL)
			ini->ant = NULL;
	}
	else
	{
		aBorrar->ant->sig = aBorrar->sig;
		if (aBorrar->sig != NULL)
			aBorrar->sig->ant = aBorrar->ant;
	}
	delete aBorrar;
}


		
void ejecutarInstruccion_SO(struct SO* so, unsigned int cpu) {
	assert(cpu < so->maxcpus);
	if (so->cpu[cpu] == NULL)
		so->cpu[cpu] = Desencolar(so->Listos);
	Proc* proc = so->cpu[cpu];
	if (proc != NULL)
	{
		proc->est = corriendo;
		proc->Idcpu = cpu;
		bool errorRecurso = false;
		unsigned int pid  = proc->Pid;
		unsigned int inst = proc->inst;
		char Cinst = proc->Pprog->code[inst-1];
		proc->inst++;
		if (Cinst != '_') {
			if (Cinst == '!') 
			{ //Lo pasa al final de la cola de procesos listos dejando el cpu libre. 
				Encolar(so->Listos,proc);
				proc->est = listo;
				so->cpu[cpu] = NULL;
			}
			else if (isupper(Cinst)) 
			{ //Pide el recurso identificado por 'Cinst'.
				int lugar = Cinst - 'A'; 
				if (so->RSo[lugar].duenio == NULL) //El recurso esta libre, el proceso 'proc' pasa a ser su dueño.
				{	
					so->RSo[lugar].duenio = proc;
					so->RSo[lugar].rproc = EncolarRP(proc->RQTiene,tolower(Cinst));
				}
				else
				{ //El recurso esta ocupado. El proceso se bloquea.
					Encolar(so->Bloq,proc);
					so->cpu[cpu] = NULL;
					proc->est = bloqueado;
					proc->RQEspera = tolower(Cinst);
					proc->Prec = EncolarRQ(so->RSo[lugar],proc);
				}
			}
			else if (islower(Cinst)) //Libera el recurso identificado por 'Cinst'.
			{	
				if (so->RSo[Cinst-'a'].duenio == proc)
					LiberarRecurso(Cinst,proc,so);
				else
					errorRecurso = true;	
			}
			else if (Cinst == '@') 		
			{ //Termina el proceso dejando al cpu libre y liberando todos los recursos que tenga.
				LiberarRecursos(proc,so);
				delete proc->RQTiene;
				int hashpos = (pid % Tam_Hash);
				SacarPHash(so->Hash->CHash[hashpos],proc->Phash);
				so->cpu[cpu] = NULL;
				delete proc;
			}
			else
				errorRecurso = true;
		}
		
		if (!errorRecurso) {
			cout << "CPU=" << cpu << " ";
			cout << "PID=" << pid << " ";
			cout << "I=" << Cinst << endl;
		}
	}
}


//Busca el proceso con id 'id' en el hash y devuelve un puntero al proceso.
//Si no lo encuentra devuelve NULL.
//Tiene orden O(1) promedio.
Proc* BuscarPHash(NHash* ini,unsigned int id) {
	NHash* pos = ini;
	bool encontre = false;
	Proc* res = NULL;
	while ((!encontre) && (pos != NULL))
	{
		if (pos->proc->Pid == id)
		{
			encontre = true;
			res = pos->proc;
		}
		pos = pos->sig;
	}
	return res;
}
	
unsigned int terminarProceso_SO(struct SO* so, unsigned int pid) {
	Proc* proc = BuscarPHash(so->Hash->CHash[pid % Tam_Hash],pid);
	if (proc == NULL)
		return SO_ERROR;
	else
	{
		LiberarRecursos(proc,so);
		delete proc->RQTiene;
		SacarPHash(so->Hash->CHash[pid % Tam_Hash],proc->Phash);
		if (proc->est == corriendo)
			so->cpu[proc->Idcpu] = NULL;
		else if (proc->est == listo)
			SacarProcC(so->Listos,proc);
		else
		{
			int rec = proc->RQEspera - 'a';
			SacarRQ(so->RSo[rec],proc->Prec);
			SacarProcC(so->Bloq,proc);
		}
		delete proc;
		return SO_OK;
	}
}


void liberar_SO(struct SO * so) {
	if (so != NULL)
	{
		for (unsigned int i = 1;i <= so->Hash->cantProc;i++)
			terminarProceso_SO(so,i);
		DestruirAVLProg(so->progs);
		delete [] so->Hash->CHash;
		delete [] so->cpu;
		delete so->Hash;
		delete so->Listos;
		delete so->Bloq;
		delete [] so->RSo;
		delete so;
		so = NULL;
	}
}






