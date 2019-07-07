/* 4317743 */

#include "CarinioEstrategia.h"
#include "ColaSimple.h"
#include <stdlib.h>
#include <string.h>



void recorr_DFS(RedInfelicidad* ri,int maq,bool* &visit,RedInfelicidad* &Tred) {
	visit[maq] = true;
	ListaSimpleConPrioridad* con = obtenerConexionesRedInfelicidad(ri,maq);
	while (!esVaciaListaSimpleConPrioridad(con))
	{
		Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(con);
		con = restoListaSimpleConPrioridad(con);
		int idM = c->idmaquina;
		if (!visit[idM])
		{
			int costo = c->costo;
			unirMaquinasRedInfelicidad(Tred,maq,idM,costo);
			recorr_DFS(ri,idM,visit,Tred);
		}
	}
}

//Hace el recorrido DFS desde la maquina con id "id_ini"
//en la red "ri" devolviendo el arbol de recubrimiento formado.
RedInfelicidad* DFS(RedInfelicidad* ri,int id_ini,int cantM) {
	RedInfelicidad* Tred = crearRedInfelicidad(cantM);
	bool* visit = new bool[cantM];
	for (int i = 0;i < cantM;i++)
		visit[i] = false;
	recorr_DFS(ri,id_ini,visit,Tred);
	delete [] visit;
	return Tred;
}

//Devuelve la cantidad de nodos de la lista 'l'.
int cantElem(ListaSimpleConPrioridad* l) {
	if (esVaciaListaSimpleConPrioridad(l))
		return 0;
	else
		return (1 + cantElem(restoListaSimpleConPrioridad(l)));
}


int maquinaCentral(RedInfelicidad* ri) {
	int cantM = cantMaquinasRedInfelicidad(ri);
	int Mcentral = 0;
	int cantMaxH = 0;
	for (int m = 0;m < cantM;m++)
	{
		RedInfelicidad* Tred = DFS(ri,m,cantM);
		ListaSimpleConPrioridad* hijos = obtenerConexionesRedInfelicidad(Tred,m);
		int cantH = cantElem(hijos);
		if (cantH > cantMaxH) {
			Mcentral = m;
			cantMaxH = cantH;
		}
		destruirRedInfelicidad(Tred);
	}
	return (Mcentral);
}


Camino* rutaMenorTiempo(RedInfelicidad* ri, int central) {
	Camino* menorCam = new Camino;
	menorCam->maquinasCamino = crearListaSimpleConPrioridad();
	menorCam->tiempo = -1;
	if (!maquinaEstaVigilada(ri,central))
	{
		menorCam->tiempo = 0;
		int* p = new int;
		*p = central;
		agregarListaSimpleConPrioridad(menorCam->maquinasCamino,(void*)p,1);
	}
	else
	{
		int cantM = cantMaquinasRedInfelicidad(ri);
		for (int mo = 0;mo < cantM;mo++)
		{
			if (!maquinaEstaVigilada(ri,mo)) //Posible ruta.
			{
				//Inicializacion de todas las estructuras.
				int* D = new int[cantM];
				int* P = new int[cantM];
				bool* C = new bool[cantM];
				ListaSimpleConPrioridad* con = obtenerConexionesRedInfelicidad(ri,mo);
				while (!esVaciaListaSimpleConPrioridad(con))
				{
					Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(con);
					con = restoListaSimpleConPrioridad(con);
					D[c->idmaquina] = c->costo;
				}
				for (int i = 0;i < cantM;i++)
				{
					P[i] = mo;
					C[i] = true;
					if (!estanConectadasMaquinasRedInfelicidad(ri,mo,i))
						D[i] = INFINITO;
				}
				D[mo] = 0;
				int v = mo;
				//Comienzo de busqueda de la maquina destino(MaqCentral).
				while (v != central)
				{
					C[v] = false;
					for (int w = 0;w < cantM;w++)
					{
						if (C[w])
						{
							int costo = 0;
							if (!estanConectadasMaquinasRedInfelicidad(ri,v,w))
								costo = INFINITO;
							else
							{
								ListaSimpleConPrioridad* con = obtenerConexionesRedInfelicidad(ri,v);
								bool encontre = false;
								while (!encontre)
								{
									Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(con);
									if (c->idmaquina == w)
									{
										costo = c->costo;
										encontre = true;
									}
									else
										con = restoListaSimpleConPrioridad(con);
								}
							}	
							if (D[w] > D[v] + costo)
							{
								D[w] = D[v] + costo;
								P[w] = v;
							}
						}
					}
					//Busqueda del siguiente v.
					int menor = INFINITO;
					for (int i = 0;i < cantM;i++)
					{
						if (C[i] && (D[i] < menor))
						{
							v = i;
							menor = D[i];
						}
					}
				}
				//Si el tiempo del camino hallado es menor que
				//el del "menorCam" actual cambio los caminos.
				if ((menorCam->tiempo == -1) || (D[central] < menorCam->tiempo))
				{
					ListaSimpleConPrioridad* l = menorCam->maquinasCamino;
					while (!esVaciaListaSimpleConPrioridad(l))
					{
						int* ptr = (int*) primeroListaSimpleConPrioridad(l);
						l = restoListaSimpleConPrioridad(l);
						delete ptr;
					}
					destruirListaSimpleConPrioridad(menorCam->maquinasCamino);
					menorCam->maquinasCamino = crearListaSimpleConPrioridad();
					menorCam->tiempo = D[central];
					//Agrego la maquina central.
					int* p = new int;
					*p = central;
					agregarListaSimpleConPrioridad(menorCam->maquinasCamino,(void*)p,1);
					v = central;
					//Agrego todas las maquinas que estan en el camino.
					while (v != mo)
					{
						int* p2 = new int;
						*p2 = P[v];
						agregarListaSimpleConPrioridad(menorCam->maquinasCamino,(void*)p2,1);
						v = P[v];
					}
				}
				delete [] D;
				delete [] P;
				delete [] C;
			}
		}
	}
	
	return (menorCam);
}


ListaSimpleConPrioridad* cariniositosEnAccion(RedInfelicidad* ri, int central, ListaSimpleConPrioridad* lc) {
	//Cola para guardar los id de maquinas.
	//Recorrido BFS.
	ColaSimple* ColaM = crearColaSimple();
	int cantM = cantMaquinasRedInfelicidad(ri);
	bool* marcadas = new bool[cantM];
	for (int i = 0;i < cantM;i++)
		marcadas[i] = false;
	marcadas[central] = true;
	//Creo la lista a devolver.
	ListaSimpleConPrioridad* CAcc = crearListaSimpleConPrioridad();
	int prio = 1;
	int* p = new int;
	*p = central;
	encolarColaSimple(ColaM,(void*)p);
	while (!esVaciaColaSimple(ColaM))
	{
		int* maq = (int*) desencolarColaSimple(ColaM);
		//Procesamiento
		CarinioAccion* ca = new CarinioAccion;
		ca->cariniosito = new char[strlen((char*)primeroListaSimpleConPrioridad(lc)) + 1];
		strcpy(ca->cariniosito,(char*)primeroListaSimpleConPrioridad(lc));
		ca->idmaquina = *maq;
		lc = restoListaSimpleConPrioridad(lc);
		agregarListaSimpleConPrioridad(CAcc,(void*)ca,prio);
		prio++;
		//Obtengo las maquinas conectadas y si no estan marcadas las encolo.
		ListaSimpleConPrioridad* con = obtenerConexionesRedInfelicidad(ri,*maq);
		delete maq;
		while (!esVaciaListaSimpleConPrioridad(con))
		{
			Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(con);
			con = restoListaSimpleConPrioridad(con);
			if (!marcadas[c->idmaquina])
			{
				marcadas[c->idmaquina] = true;
				int* p2 = new int;
				*p2 = c->idmaquina;
				encolarColaSimple(ColaM,(void*)p2);
			}
		}
	}
	delete [] marcadas;
	destruirColaSimple(ColaM);
	return (CAcc);
}

