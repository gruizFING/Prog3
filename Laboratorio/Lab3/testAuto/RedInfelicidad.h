#ifndef REDINFELICIDAD_H
#define REDINFELICIDAD_H

#include "ListaSimpleConPrioridad.h"

struct Conexion
{
	int idmaquina;
	int costo;
};

struct RedInfelicidad;

RedInfelicidad* crearRedInfelicidad(int cantmaquinas);

int cantMaquinasRedInfelicidad(RedInfelicidad* ri);

void unirMaquinasRedInfelicidad(RedInfelicidad* c, int idmaquina1, int idmaquina2, int costo);

void vigilarMaquina(RedInfelicidad* c, int idmaquina);

bool estanConectadasMaquinasRedInfelicidad(RedInfelicidad* ri, int idmaquina1, int idmaquina2);

bool maquinaEstaVigilada(RedInfelicidad* ri, int idmaquina);

ListaSimpleConPrioridad* obtenerConexionesRedInfelicidad(RedInfelicidad* ri, int idmaquina);

void destruirRedInfelicidad(RedInfelicidad* ri);

#endif /* REDINFELICIDAD_H */
