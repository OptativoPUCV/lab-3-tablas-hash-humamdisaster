#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

void insertMap(HashMap * map, char * key, void * value) {
    long pos = hash(key, map->capacity);
    Pair * parActual = map->buckets[pos];

    while (parActual != NULL){
        pos = (pos + 1) % map->capacity;
    }
    if (map->buckets[pos] == NULL){
        map->buckets[pos] = createPair(strdup(key), value);
    }
    else{
        map->buckets[pos]->key = strdup(key);
        map->buckets[pos]->value = strdup(value);
    }
    if (map->capacity / map->size >= 0.7){
        enlarge(map);
    }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

    return NULL;
}

void eraseMap(HashMap * map,  char * key) {    


}

/* 3.- Implemente la función Pair * searchMap(HashMap * map,  char * key), la cual retorna el **Pair** asociado a la clave ingresada. 
Recuerde que para buscar el par debe:

a - Usar la función hash para obtener la posición donde puede encontrarse el par con la clave

b - Si la clave no se encuentra avance hasta encontrarla (*método de resolución de colisiones*)

c - Si llega a una casilla nula, retorne NULL inmediatamente (no siga avanzando, la clave no está)

Recuerde actualizar el índice current a la posición encontrada.
Recuerde que el arreglo es **circular**.

    Pair * searchMap(HashMap * map,  char * key) {


        return NULL;
    }

*/

Pair * searchMap(HashMap * map,  char * key) {   
    
    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
