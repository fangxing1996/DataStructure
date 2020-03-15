#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int ElemType;
#define INIT_SIZE 100
#define INCREMENT 10
struct linearlist{

    ElemType* elem;
    int length;
    int listsize;
};
typedef struct linearlist linearlist;
int linearlist_init(linearlist* l);
int linearlist_add(linearlist* l, ElemType a);
#endif
