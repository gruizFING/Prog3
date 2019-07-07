/*
 * Tarea 2
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 *
 * $Rev: 189 $
 *
 * Nombres de recursos posibles:
 * A B C D E F G H I J 
 * K L M N O P Q R S T 
 * U V W X Y Z 
 */
#ifndef SO_H
#define SO_H

#define SO_ERROR 0
#define SO_OK 	 1

struct SO;

/*
 * Inicializa las estructuras internas con 'maxcpus' CPUs.
 * En caso de error devuelve NULL
 */
struct SO* iniciar_SO(unsigned int maxcpus);

/*
 * Agrega al SO un programa con nombre 'nombre' y su 
 * código asociado 'codigo'.
 * Pre: - No existe un programa con nombre 'nombre'
 *      - Todo código termina con '@'
 * Retorna SO_OK en caso de éxito, SO_ERROR en caso contrario.
 */
int crearPrograma_SO(struct SO *, const char* nombre, const char *codigo);

/*
 * Imprime los nombres de los programas
 * que hay en el SO.
 */
void imprimirProgramas_SO(struct SO* so);

/*
 * Crea un proceso ejecutando el programa con nombre 'nombre'.
 * Retorna el identificador del proceso, si no existe el programa
 * devuelve 0.
 */
unsigned int ejecutar_SO(struct SO *, const char* nombre);

/*
 * Imprime la información relacionada a los
 * procesos en estado bloqueado.
 */
void imprimirProcesosBloqueados_SO(struct SO*);

/*
 * Imprime la información relacionada a los
 * procesos en estado listo.
 */
void imprimirProcesosListos_SO(struct SO*);

/*
 * Ejecuta la próxima instrucción del proceso en el
 * procesador 'cpu'
 * Pre: cpu < maxcpus
 */
void ejecutarInstruccion_SO(struct SO*, unsigned int cpu);

/*
 * Termina el proceso con identificador 'pid'
 * Devuelve SO_OK en caso de éxito, SO_ERROR en caso contrario.
 */
unsigned int terminarProceso_SO(struct SO*, unsigned int pid);

/*
 * Libera toda la memoria asociada a la estructura SO.
 */
void liberar_SO(struct SO *);

#endif
