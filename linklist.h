#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int ElemType;
struct node{

    ElemType data;
    struct node* next;
};

typedef struct node node;
void linklist_init(node* p);
void linklist_add(node* p, ElemType a);
void linklist_del(node* p);
void linklist_output(node* p);
#endif
