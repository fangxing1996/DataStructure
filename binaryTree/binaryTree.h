#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include<iostream>
#include<algorithm>
using namespace std;
#define ElemType int
struct node{
    ElemType data;
    struct node* lc;
    struct node* rc;
    node(): data(0), lc(NULL), rc(NULL){

    }
};
class BinaryTree{
    private:
        node* root;
        int size;
    public:
        enum treeSize{minSize = 0, maxSize = 32767};
    public:
        BinaryTree();
        virtual ~BinaryTree();
        void insertNode(ElemType key);
        node* insert(node* pnode, ElemType key);
        void preOrder();
        void inOrder();
        void postOrder();
        void preOrderTraverse(node* pnode);
        void inOrderTraverse(node* pnode);
        void postOrderTraverse(node* pnode);
        void removeTree();
        void removeAll(node* pnode);
        void removeNode();
        node* getMinNode(node* pnode);
        node* getMaxNode(node* pnode);
        node* getRootNode();
        node* getParentNode(ElemType key);
        node* query(ElemType key);
        node* queryNode(node* node, ElemType key);
        int getDepthAll();
        int getDepthNode(node* pnode);
        int getSize();
        void addSize();
        void subSize();

};
#endif
