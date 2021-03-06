#include <stdlib.h>
#include "rocksdb/c.h"

// This API provides convenient C wrapper functions for rocksdb client.

/* Base */

extern void gorocksdb_destruct_handler(void* id);

/* Comparator */

extern rocksdb_comparator_t* gorocksdb_comparator_create(size_t id);

/* Filter Policy */

extern rocksdb_filterpolicy_t* gorocksdb_filterpolicy_create(size_t id);
extern void gorocksdb_filterpolicy_delete_filter(void* id, const char* v, size_t s);

/* Merge Operator */

extern rocksdb_mergeoperator_t* gorocksdb_mergeoperator_create(size_t id);
extern void gorocksdb_mergeoperator_delete_value(void* id, const char* v, size_t s);

/* Slice Transform */

extern rocksdb_slicetransform_t* gorocksdb_slicetransform_create(size_t id);

/* Hacks */

// According to the answer of :https://groups.google.com/forum/#!msg/golang-nuts/6toTzvJbyIs/sLQF6NLn-wIJ
// There is no pointer arithmetic in Go.
// the following functions gives an easy approach to get a entry at a specified index
extern char* gorocksdb_get_char_at_index(char **list, int idx);
extern size_t gorocksdb_get_int_at_index(size_t *list, int idx);