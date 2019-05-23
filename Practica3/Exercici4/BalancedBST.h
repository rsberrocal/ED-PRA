/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBST.h
 * Author: Rocho
 *
 * Created on 20 de mayo de 2019, 22:20
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H

#include <cstddef>
#include <iostream>

#include "NodeTree.h"

using namespace std;

template <class Type>
class BalancedBST {
public:
    /*Constructors i Destructors*/
    BalancedBST();
    BalancedBST(const BalancedBST & orig);
    virtual ~BalancedBST();
    /*Consultors*/
    int size() const;
    bool isEmpty() const;
    NodeTree<Type>* root();
    bool search(const Type& element);
    void showInorder() const;
    void showPreorder() const;
    void showPostorder() const;
    void showLeafNodes() const;
    int height();
    int depth();
    /*Modificadors*/
    void insert(const Type& element);
private:
    bool needRotate();
    int getBalanceFactor();
    int size(NodeTree<Type>* p) const;
    void showPreorder(NodeTree<Type>* p) const;
    void showPostorder(NodeTree<Type>* p) const;
    void showInorder(NodeTree<Type>* p) const;
    void showLeafNodes(NodeTree<Type>* p)const;
    void deletingNodes(NodeTree<Type>* p)const;
    void copyNodes(NodeTree<Type>* p, NodeTree<Type>* n)const;
    int height(NodeTree<Type>* p);
    int depth(NodeTree<Type>* p);
    /*Atributs*/
    NodeTree<Type>* pRoot;
};

template <class Type>
BalancedBST<Type>::BalancedBST() {
    cout << "Arbre binari creat" << endl;
    this->pRoot = nullptr;
}

template <class Type>
BalancedBST<Type>::BalancedBST(const BalancedBST& orig) {
    this->pRoot = new NodeTree<Type>();
    this->copyNodes(orig.root(), this->pRoot);
}

template <class Type>
void BalancedBST<Type>::copyNodes(NodeTree<Type>* p, NodeTree<Type>* n) const {
    if (p->isExternal()) {
        n->setElement(p->getElement());
        return;
    } else {
        NodeTree<Type>* newLeft = new NodeTree<Type>();
        NodeTree<Type>* newRight = new NodeTree<Type>();
        n->setElement(p->getElement());
        if (p->hasLeft()) {
            n->setLeft(newLeft);
            this->copyNodes(p->left(), n->left());
        }
        if (p->hasRight()) {
            n->setRight(newRight);
            this->copyNodes(p->right(), n->right());
        }

    }
}

template <class Type>
BalancedBST<Type>::~BalancedBST() {
    cout << "Destruint arbre binari" << endl;
    this->deletingNodes(this->pRoot);
    cout << "Arbre binari destruit " << endl;
}

template <class Type>
void BalancedBST<Type>::deletingNodes(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << "Eliminant node " << p->getElement() << endl;
        delete p;
    } else {
        if (p->hasLeft())
            this->deletingNodes(p->left());
        if (p->hasRight())
            this->deletingNodes(p->right());
        cout << "Elimnant node " << p->getElement() << endl;
        delete p;
    }
}

template <class Type>
int BalancedBST<Type>::size() const {
    if (this->isEmpty()) {
        return 0;
    } else {
        return this->size(this->pRoot);
    }
}

template <class Type>
int BalancedBST<Type>::size(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        return 1;
    } else {
        return this->size(p->left()) + this->size(p->right()) + 1;
    }
}

template <class Type>
bool BalancedBST<Type>::isEmpty() const {
    return this->pRoot == nullptr;
}

template <class Type>
void BalancedBST<Type>::insert(const Type& element) {
    NodeTree<Type>* newNode = new NodeTree<Type>(element);
    if (this->isEmpty()) {
        this->pRoot = newNode;
    } else {
        NodeTree<Type>* actualNode = this->pRoot;
        bool nodeSet = false;
        while (!nodeSet) {
            if (actualNode->isExternal()) {
                if (actualNode->getElement() < element) {
                    actualNode->setRight(newNode);
                } else {
                    actualNode->setLeft(newNode);
                }
                newNode->setParent(actualNode);
                nodeSet = true;
            } else {
                if (actualNode->getElement() < element) {
                    if (!actualNode->hasRight()) {
                        actualNode->setRight(newNode);
                        newNode->setParent(actualNode);
                        nodeSet = true;
                    } else {
                        actualNode = actualNode->right();
                    }
                } else {
                    if (!actualNode->hasLeft()) {
                        actualNode->setLeft(newNode);
                        newNode->setParent(actualNode);
                        nodeSet = true;
                    } else {
                        actualNode = actualNode->left();
                    }
                }
            }
        }
    }
    cout << "Inserta a l'arbre element: " << element << endl;
}

template <class Type>
NodeTree<Type>* BalancedBST<Type>::root() {
    return this->pRoot;
}

template <class Type>
bool BalancedBST<Type>::search(const Type& element) {
    bool found = false;
    if (this->isEmpty()) {
        throw "ERROR: Empty Tree";
    } else {
        NodeTree<Type>* actualNode = this->root();
        while (!found && actualNode) {
            if (actualNode->getElement() == element) {
                found = true;
            } else {
                if (actualNode->getElement() <= element) {
                    actualNode = actualNode->right();
                } else {
                    actualNode = actualNode->left();
                }
            }
        }
    }
    return found;
}

template <class Type>
void BalancedBST<Type>::showInorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Inordre = {";
        this->showInorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BalancedBST<Type>::showInorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getElement() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showInorder(p->left());
        cout << p->getElement() << ", ";
        if (p->hasRight())
            this->showInorder(p->right());
    }
}

template <class Type>
void BalancedBST<Type>::showPostorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Postordre = {";
        this->showPostorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BalancedBST<Type>::showPostorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getElement() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showPostorder(p->left());
        if (p->hasRight())
            this->showPostorder(p->right());
        cout << p->getElement() << ", ";
    }
}

template <class Type>
void BalancedBST<Type>::showPreorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Preorder = {";
        this->showPreorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BalancedBST<Type>::showPreorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getElement() << ", ";
        return;
    } else {
        cout << p->getElement() << ", ";
        if (p->hasLeft())
            this->showPreorder(p->left());
        if (p->hasRight())
            this->showPreorder(p->right());
    }
}

template <class Type>
void BalancedBST<Type>::showLeafNodes() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Fulles = {";
        this->showLeafNodes(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BalancedBST<Type>::showLeafNodes(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getElement() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showLeafNodes(p->left());
        if (p->hasRight())
            this->showLeafNodes(p->right());
    }
}

template <class Type>
int BalancedBST<Type>::height() {
    if (isEmpty()) {
        return 0;
    } else {
        return this->height(this->pRoot);
    }
}

template <class Type>
int BalancedBST<Type>::height(NodeTree<Type>* p) {
    if (p == nullptr) {
        return 0;
    } else {
        return max(height(p->left()), height(p->right())) + 1;
    }
}

template <class Type>
int BalancedBST<Type>::depth() {

}

template <class Type>
int BalancedBST<Type>::depth(NodeTree<Type>* p) {
    if (p == nullptr) {
        return 0;
    } else {
        return (p->parent()) + 1;
    }
}

template <class Type>
bool BalancedBST<Type>::needRotate() {

}

int BalancedBST<Type>::getBalanceFactor() {

}
#endif /* BALANCEDBST_H */

