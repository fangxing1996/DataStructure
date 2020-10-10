#include "binaryTree.h"
BinaryTree::BinaryTree(): root(NULL), size(0){

}

BinaryTree::~BinaryTree(){

}

void BinaryTree::insertNode(ElemType key){
    int curSize = getSize();
    if(curSize == maxSize){
        cout << "Insert node error, the size of binaryTree if max!" << endl;
        return ;
    }
    root = insert(root, key);
    return ;
}

node* BinaryTree::insert(node* pnode, ElemType key){
    if(pnode == NULL){
        node* newNode = new(std::nothrow) node;
        if(newNode != NULL){
            newNode -> data = key;
            newNode -> lc = NULL;
            newNode -> rc = NULL;
            pnode = newNode;
            addSize();
        }
        return pnode;
    }
    if(pnode -> data > key){
        pnode -> lc = insert(pnode -> lc, key);
    }
    else if(pnode -> data < key){
        pnode -> rc = insert(pnode -> rc, key);
    }
    return pnode;
}

void BinaryTree::preOrder(){
    preOrderTraverse(root);
    cout << endl;
}

void BinaryTree::inOrder(){
    inOrderTraverse(root);
    cout << endl;
}

void BinaryTree::postOrder(){
    postOrderTraverse(root);
    cout << endl;
}

void BinaryTree::preOrderTraverse(node* pnode){
    if(pnode != NULL){
        cout << pnode -> data << ' ';
        preOrderTraverse(pnode -> lc);
        preOrderTraverse(pnode -> rc);
    }
    return ;
}

void BinaryTree::inOrderTraverse(node* pnode){
    if(pnode != NULL){
        inOrderTraverse(pnode -> lc);
        cout << pnode -> data << ' ';
        inOrderTraverse(pnode -> rc);
    }
    return ;
}

void BinaryTree::postOrderTraverse(node* pnode){
    if(pnode != NULL){
        postOrderTraverse(pnode -> lc);
        postOrderTraverse(pnode -> rc);
        cout << pnode -> data << ' ';
    }
    return ;
}

void BinaryTree::removeTree(){
    if(root == NULL){
        cout << "Remove tree failed, root = NULL! " << endl;
        return ;
    }
    removeAll(root);
    if(getSize() == 0)
        root = NULL;
    return ;
}

void BinaryTree::removeAll(node* pnode){
    if(pnode != NULL){
        removeAll(pnode -> lc);
        removeAll(pnode -> rc);
        delete pnode;
        subSize();
    }
}

void BinaryTree::removeNode(ElemType deldata){
    if(root == NULL){
        cout << "Remove failed, root = NULL!";
        return ;
    }
    node* parentNode = NULL;
    node* delNode = root;
}
node* getMinNode(node* pnode){
    if(pnode -> lc == NULL){
        return pnode;
    }
    return getMinNode(pnode -> lc);
}

node* getMaxNode(node* pnode){
    if(pnode -> rc == NULL)
        return pnode;
    return getMaxNode(pnode);
}

node* BinaryTree::getRootNode(){
    return root;
}

node* BinaryTree::getParentNode(ElemType key){
    node *curNode, *parentNode;
    curNode = NULL;
    parentNode = NULL;
    bool isFind = false;
    curNode = root;
    while(curNode){

        if(curNode -> data == key){
            isFind = true;
            break;
        }
           
        if(curNode -> data > key){
            parentNode = curNode;
            curNode = curNode -> lc;
        }
        else if(curNode -> data < key){
            parentNode = curNode;
            curNode = curNode -> rc;
        }
    }
    return (isFind == true) ? parentNode: NULL;
}

node* BinaryTree::query(ElemType key){
    if(root == NULL){
        cout << "Query failed, root = NULL！";
        return NULL;
    }
    return queryNode(root, key);
}

node* BinaryTree::queryNode(node* pnode, ElemType key){
    if(pnode == NULL){
        return pnode;
    }
    if(pnode -> data == key){
        return pnode;
    }
    else if(pnode -> data > key){
        return queryNode(pnode -> lc, key);
    }
    else if(pnode -> data < key){
        return queryNode(pnode -> rc, key);
    }
    return NULL;
}



int BinaryTree::getDepthAll(){
    return getDepthNode(root);
}

int BinaryTree::getDepthNode(node* pnode){
    int depth = 0;
    if(pnode == NULL){
    }
    else{
        depth++;
        depth += max(getDepthNode(pnode -> lc), getDepthNode(pnode -> rc));
    }
    return depth;
}

int BinaryTree::getSize(){
    return size;
}

void BinaryTree::addSize(){
    size++;
}

void BinaryTree::subSize(){
    size--;
}

