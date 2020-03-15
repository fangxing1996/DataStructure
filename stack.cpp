#include "stack.h"

void init(stack* p){
    p->top = -1;
}

void push(stack* p, ElemType a){

    p->node[++p->top] = a;
}

ElemType pop(stack* p){
    if(p->top == -1){
        cout << "stack is empty" << endl;
        return -1;
    }
    else
        return p->node[p->top--];    
}

int isempty(stack* p){

    if(p->top == -1)
        return 1;
    else
        return 0;
}

int length(stack* p){

    return (p->top + 1);
}
