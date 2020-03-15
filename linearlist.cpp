#include "linearlist.h"
int linearlist_init(linearlist* l){

    l->elem = (ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!l->elem)
        return -1;
    l->length = 0;
    l->listsize = INIT_SIZE;
    return 0;
}

int linearlist_add(linearlist* l, ElemType a){

    if(l->length >= l->listsize){

        ElemType* newbase;
        newbase = (ElemType*)realloc(l->elem, (l->listsize + INCREMENT)*sizeof(ElemType));
        if(!newbase)
            return -1;
        l->elem = newbase;
        l->listsize += INCREMENT; 
    }
    *(l->elem + l->length++) = a;
    return 0;
}
