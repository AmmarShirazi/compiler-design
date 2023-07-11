#include "table.h"

Table_ Table(string id, int value, struct table *tail) {
    
    Table_ t = malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->tail = tail;
    
    return t;
}

Table_ interpStm(A_stm s, Table_ t) {

}