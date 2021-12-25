#ifndef SET_H
#define SET_H

#define MAX_SIZE 4096
#define PRIME 786433 // for sizes b/w 2^19 and 2^20 https://planetmath.org/goodhashtableprimes

/*
 * keys for this hash table are strings
 * and the values are integers.
 */
typedef char keyType[MAX_SIZE];

typedef struct set_elt {
    keyType key;
    struct ht_elt *next;
} ht_elt;

typedef struct set {
    struct set_elt **table;
    int capacity;
    int num_elt;
} hashtable;


int allocate(set **map, int size);

int insert(set *map, keyType key, valType val);

int get(set *map, keyType key, valType *val);

int erase(set *map, keyType key);

int deallocate(set **map);

#endif
