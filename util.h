#ifndef UTIL_H
#define UTIL_H
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "grammar.h"

typedef char* string;
string String(char*);
typedef char bool;
#define TRUE 1
#define FALSE 0
void* checked_malloc(int);
int maxargs(A_stm);
int max(int n1, int n2);
int check_exp(A_exp  exp);
int maxargs(A_stm stm);

#endif