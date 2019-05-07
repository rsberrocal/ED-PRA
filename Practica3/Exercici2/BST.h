/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 25 / d’abril / 2019, 11:40
 */

#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>

#include "NodeTree.h"

using namespace std;

template <class Type>
class BST {
public:
    /*Constructors i Destructors*/
    BST();
    BST(const BST & orig);
    virtual ~BST();
    /*Consultors*/
    int size() const;
    bool isEmpty() const;
    NodeTree<Type>* root();
    bool search(int key);
    Type* getValue(int key);
    void showInorder() const;
    void showPreorder() const;
    void showPostorder() const;
    void showLeafNodes() const;
    /*Modificadors*/
    void insert(Type* element, int key);
private:
    int size(NodeTree<Type>* p) const;
    void showPreorder(NodeTree<Type>* p) const;
    void showPostorder(NodeTree<Type>* p) const;
    void showInorder(NodeTree<Type>* p) const;
    void showLeafNodes(NodeTree<Type>* p)const;
    void deletingNodes(NodeTree<Type>* p)const;
    void copyNodes(NodeTree<Type>* p, NodeTree<Type>* n)const;
    /*Atributs*/
    NodeTree<Type>* pRoot;
};

template <class Type>
BST<Type>::BST() {
    cout << "Arbre binari creat" << endl;
    this->pRoot = nullptr;
}

template <class Type>
BST<Type>::BST(const BST& orig) {
    this->pRoot = new NodeTree<Type>();
    this->copyNodes(orig.root(), this->pRoot);
}

template <class Type>
void BST<Type>::copyNodes(NodeTree<Type>* p, NodeTree<Type>* n) const {
    if (p->isExternal()) {
        n->setKey(p->getKey());
        n->setValue(p->getValue());
        return;
    } else {
        NodeTree<Type>* newLeft = new NodeTree<Type>();
        NodeTree<Type>* newRight = new NodeTree<Type>();
        n->setValue(p->getValue());
        n->setKey(p->getKey());
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
BST<Type>::~BST() {
    cout << "Destruint arbre binari" << endl;
    this->deletingNodes(this->pRoot);
    cout << "Arbre binari destruit " << endl;
}

template <class Type>
void BST<Type>::deletingNodes(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << "Eliminant node " << p->getKey() << endl;
        delete p;
    } else {
        if (p->hasLeft())
            this->deletingNodes(p->left());
        if (p->hasRight())
            this->deletingNodes(p->right());
        cout << "Elimnant node " << p->getKey() << endl;
        delete p;
    }
}

template <class Type>
int BST<Type>::size() const {
    if (this->isEmpty()) {
        return 0;
    } else {
        return this->size(this->pRoot);
    }
}

template <class Type>
int BST<Type>::size(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        return 1;
    } else {
        return this->size(p->left()) + this->size(p->right()) + 1;
    }
}

template <class Type>
bool BST<Type>::isEmpty() const {
    return this->pRoot == nullptr;
}

template <class Type>
void BST<Type>::insert(Type* element, int key) {
    NodeTree<Type>* newNode = new NodeTree<Type>(element, key);
    if (this->isEmpty()) {
        this->pRoot = newNode;
    } else {
        NodeTree<Type>* actualNode = this->pRoot;
        bool nodeSet = false;
        while (!nodeSet) {
            if (actualNode->isExternal()) {
                if (actualNode->getKey() < newNode->getKey()) {
                    actualNode->setRight(newNode);
                } else {
                    actualNode->setLeft(newNode);
                }
                newNode->setParent(actualNode);
                nodeSet = true;
            } else {
                if (actualNode->getKey() < newNode->getKey()) {
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
    cout << "Inserta a l'arbre element: " << newNode->getKey() << endl;
}

template <class Type>
NodeTree<Type>* BST<Type>::root() {
    return this->pRoot;
}

template <class Type>
bool BST<Type>::search(const int key) {
    bool found = false;
    if (this->isEmpty()) {
        throw "ERROR: Empty Tree";
    } else {
        NodeTree<Type>* actualNode = this->root();
        while (!found && actualNode) {
            if (actualNode->getKey() == key) {
                found = true;
            } else {
                if (actualNode->getKey() <= key) {
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
Type* BST<Type>::getValue(int key) {
    Mountain* mountain = nullptr;
    bool found = false;
    if (this->isEmpty()) {
        throw "ERROR: Empty Tree";
    } else {
        NodeTree<Type>* actualNode = this->root();
        while (!found && actualNode) {
            if (actualNode->getKey() == key) {
                mountain = actualNode->getValue();
            } else {
                if (actualNode->getKey() <= key) {
                    actualNode = actualNode->right();
                } else {
                    actualNode = actualNode->left();
                }
            }
        }
    }
    return mountain;
}

template <class Type>
void BST<Type>::showInorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Inordre = {";
        this->showInorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BST<Type>::showInorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getValue().toString() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showInorder(p->left());
        cout << p->getValue().toString() << ", ";
        if (p->hasRight())
            this->showInorder(p->right());
    }
}

template <class Type>
void BST<Type>::showPostorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Postordre = {";
        this->showPostorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BST<Type>::showPostorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getValue().toString() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showPostorder(p->left());
        if (p->hasRight())
            this->showPostorder(p->right());
        cout << p->getValue().toString() << ", ";
    }
}

template <class Type>
void BST<Type>::showPreorder() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Preorder = {";
        this->showPreorder(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BST<Type>::showPreorder(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getValue().toString() << ", ";
        return;
    } else {
        cout << p->getValue().toString() << ", ";
        if (p->hasLeft())
            this->showPreorder(p->left());
        if (p->hasRight())
            this->showPreorder(p->right());
    }
}

template <class Type>
void BST<Type>::showLeafNodes() const {
    if (this->isEmpty()) {
        throw "ERROR: Tree Empty";
    } else {
        cout << "Fulles = {";
        this->showLeafNodes(this->pRoot);
        cout << "}" << endl;
    }
}

template <class Type>
void BST<Type>::showLeafNodes(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        cout << p->getValue().toString() << ", ";
        return;
    } else {
        if (p->hasLeft())
            this->showLeafNodes(p->left());
        if (p->hasRight())
            this->showLeafNodes(p->right());
    }
}

#endif /* BST_H */

