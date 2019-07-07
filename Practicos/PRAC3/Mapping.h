/* TAD Mapping - Ej10Pr3 */
#ifndef Mapping_H
#define Mapping_H

struct nodoMapping;
typedef nodoMapping* mapping;

mapping Crear(int Tam);
//Crea un mapping de tamaño 'Tam'.

void Insertar(mapping &m,int dom,int cod);
//Inserta el par (dom,cod) en el mapping 'm'.

bool Pertenece(mapping m,int dom);
//Devuelve true si 'dom' pertenece a 'm'.

int Computar(mapping m,int dom);
//Devuelve el valor correspondiente a 'dom' en 'm'.
//Pre: Pertenece(m,dom).

#endif /* Mapping_H */
