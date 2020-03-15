#include "linklist.h"
void linklist_init(node* p){

    p->data = 0;
    p->next = NULL;
}
void linklist_output(node* p){

    node* r;
    r = p;
    while(p->next != NULL){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << p->data;
}

void linklist_add(node* p, ElemType a){

    node* r;
    node* x;
    r = p;
    x = (node*)malloc(sizeof(node));
    x->data = a;
    x->next = NULL;
    while(r->next != NULL){
            r = r->next;
    }
    r->next = x;
}

void linklist_del(node* p){

    int count = 0;
    node* r;
    node* t;
    r = p;
    while(r->next != NULL){
        t = r;
        r = r->next;
        count++;
    }
    if(count == 0)
        cout << "can't delete first node" << endl;
    else{
        free(r);
        t->next = NULL;
    }
}
