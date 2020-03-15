#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
using namespace std;
typedef int ElemType;
#define SIZE 100
struct stack{
    
    ElemType  node[SIZE];
    int top;
};
typedef struct stack stack;
void init(stack* p);
void push(stack* p, ElemType a);
ElemType pop(stack* p);
int isempty(stack* p);
int length(stack* p);
#endif
