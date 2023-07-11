#include "util.h"

string String(char *str) {
    string s = checked_malloc(strlen(str)+1);
    strcpy(s, str);
    return s;
}

void* checked_malloc(int len) {

    void* p = malloc(len);
    assert(p);

    return p;
}

int max(int n1, int n2) {
    return (n1 > n2)? n1 : n2;
}

int check_exp(A_exp  exp) {


    if (exp == NULL) {
        return 0;
    }

    if (exp->kind == A_opExp) {
        return max(check_exp(exp->u.op.left), check_exp(exp->u.op.right));
    }
    else if (exp->kind == A_eseqExp) {
        return max(maxargs(exp->u.eseq.stm), check_exp(exp->u.eseq.exp));   
    }    
    

    return 0;
}

int maxargs(A_stm stm) {

    if (stm == NULL) {
        return 0;
    }

    int max_count = 0;

    if (stm->kind == A_compoundStm) {
        max_count = max(maxargs(stm->u.compound.stm1), maxargs(stm->u.compound.stm2));
    }
    else if (stm->kind == A_assignStm) {
        max_count = check_exp(stm->u.assign.exp);
    }
    else if (stm->kind == A_printStm) {
        
        A_expList current = stm->u.print.exps;
        int count = 0;

        while (current != NULL) {
            count++;
            if (current->kind == A_pairExpList) {
                int nested_count = check_exp(current->u.pair.head);
                if (nested_count > count) {
                    count = nested_count;
                }
                current = current->u.pair.tail;
            } else { // must be a A_lastExpList
                int nested_count = check_exp(current->u.last);
                if (nested_count > count) {
                    count = nested_count;
                }
                current = NULL;
            }
        }
        max_count = max(count, max_count);

    }

    return max_count;
}