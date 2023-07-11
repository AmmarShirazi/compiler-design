#include "util.h"

typedef struct table *Table_;
struct table {
    string id;
    int value;
    Table_ tail;
};


Table_ interpStm(A_stm s, Table_ t);