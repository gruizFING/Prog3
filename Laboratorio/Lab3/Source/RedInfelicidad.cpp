/* 4317743 */

#include "RedInfelicidad.h"
#include <stdlib.h>
#include <assert.h>

struct Conexiones {
	ListaSimpleConPrioridad* conex;
	bool vigilada;
};

struct RedInfelicidad {
	Conexiones** red;
	int cantMaq;
};


RedInfelicidad* crearRedInfelicidad(int cantmaquinas) {
	assert(cantmaquinas >= 0);
	RedInfelicidad* ri = new RedInfelicidad;
	ri->cantMaq = cantmaquinas;
	ri->red = new Conexiones*[cantmaquinas];
	for (int i = 0;i < cantmaquinas;i++)
	{
		ri->red[i] = new Conexiones;
		ri->red[i]->vigilada = false;
		ri->red[i]->conex = crearListaSimpleConPrioridad();
	}
	return ri;
}


int cantMaquinasRedInfelicidad(RedInfelicidad* ri) {
	return (ri->cantMaq);
}

void ArmarListaConexiones(ListaSimpleConPrioridad* l,ListaSimpleConPrioridad* &n,int id) {
	if (!esVaciaListaSimpleConPrioridad(l))
	{
		ArmarListaConexiones(restoListaSimpleConPrioridad(l),n,id);
		Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(l);
		if (c->idmaquina != id)
			agregarListaSimpleConPrioridad(n,(void*)c,c->costo);
	}
}
	
void unirMaquinasRedInfelicidad(RedInfelicidad* c, int idmaquina1, int idmaquina2, int costo) {
	if (((idmaquina1 < c->cantMaq) && (idmaquina1 >= 0)) &&
	    ((idmaquina2 < c->cantMaq) && (idmaquina2 >= 0)) &&
		 (idmaquina1 != idmaquina2))
	{
		if (!estanConectadasMaquinasRedInfelicidad(c,idmaquina1,idmaquina2))
		{
			Conexiones* con1 = c->red[idmaquina1];
			Conexiones* con2 = c->red[idmaquina2];
			Conexion* c1 = new Conexion;
			Conexion* c2 = new Conexion;
			c1->idmaquina = idmaquina2;
			c1->costo = costo;
			c2->idmaquina = idmaquina1;
			c2->costo = costo;
			agregarListaSimpleConPrioridad(con1->conex,(void*)c1,costo);
			agregarListaSimpleConPrioridad(con2->conex,(void*)c2,costo);
		}
		else
		{
			ListaSimpleConPrioridad* l = c->red[idmaquina1]->conex;
			bool encontre = false;
			Conexion* con;
			while (!encontre)
			{
				con = (Conexion*) primeroListaSimpleConPrioridad(l);
				if (con->idmaquina == idmaquina2)
					encontre = true;
				else
					l = restoListaSimpleConPrioridad(l);
			}
			bool cambio = (con->costo != costo);
			if (cambio)
			{
				con->costo = costo;
				l = c->red[idmaquina1]->conex;
				ListaSimpleConPrioridad* nuevaConex = crearListaSimpleConPrioridad();
				ArmarListaConexiones(l,nuevaConex,idmaquina2);
				agregarListaSimpleConPrioridad(nuevaConex,(void*)con,costo);
				destruirListaSimpleConPrioridad(l);
				c->red[idmaquina1]->conex = nuevaConex;
				
				l = c->red[idmaquina2]->conex;
				encontre = false;
				while (!encontre)
				{
					con = (Conexion*) primeroListaSimpleConPrioridad(l);
					if (con->idmaquina == idmaquina1)
						encontre = true;
					else
						l = restoListaSimpleConPrioridad(l);
				}
				con->costo = costo;
				l = c->red[idmaquina2]->conex;
				nuevaConex = crearListaSimpleConPrioridad();
				ArmarListaConexiones(l,nuevaConex,idmaquina1);
				agregarListaSimpleConPrioridad(nuevaConex,(void*)con,costo);
				destruirListaSimpleConPrioridad(l);
				c->red[idmaquina2]->conex = nuevaConex;
				
			}
		}
	}
}


void vigilarMaquina(RedInfelicidad* c, int idmaquina) {
	if ((idmaquina < c->cantMaq) && (idmaquina >= 0))
		c->red[idmaquina]->vigilada = true;
}


bool estanConectadasMaquinasRedInfelicidad(RedInfelicidad* ri, int idmaquina1, int idmaquina2) {
	bool conectadas = false;
	if (((idmaquina1 < ri->cantMaq) && (idmaquina1 >= 0)) &&
	    ((idmaquina2 < ri->cantMaq) && (idmaquina2 >= 0)) &&
		 (idmaquina1 != idmaquina2))
	{
		ListaSimpleConPrioridad* l = ri->red[idmaquina1]->conex;
		while ((!esVaciaListaSimpleConPrioridad(l)) && (!conectadas))
		{
			Conexion* con = (Conexion*)primeroListaSimpleConPrioridad(l);
			l = restoListaSimpleConPrioridad(l);
			if (con->idmaquina == idmaquina2)
				conectadas = true;
		}
	}
	return (conectadas);
}


bool maquinaEstaVigilada(RedInfelicidad* ri, int idmaquina) {
	if ((idmaquina < ri->cantMaq) && (idmaquina >= 0))
		return (ri->red[idmaquina]->vigilada);
	else
		return false;
}


ListaSimpleConPrioridad* obtenerConexionesRedInfelicidad(RedInfelicidad* ri, int idmaquina) {
	assert((idmaquina < ri->cantMaq) && (idmaquina >= 0));
	return (ri->red[idmaquina]->conex);
}


void destruirRedInfelicidad(RedInfelicidad* ri) {
	for (int i = 0;i < ri->cantMaq;i++)
	{
		ListaSimpleConPrioridad* con = ri->red[i]->conex;
		while (!esVaciaListaSimpleConPrioridad(con))
		{
			Conexion* c = (Conexion*) primeroListaSimpleConPrioridad(con);
			con = restoListaSimpleConPrioridad(con);
			delete c;
		}
		destruirListaSimpleConPrioridad(ri->red[i]->conex);
		delete ri->red[i];
	}
	delete [] ri->red;
	delete ri;
}

