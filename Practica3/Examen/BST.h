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
    bool search(const Type& element);
    void showInorder() const;
    void showPreorder() const;
    void showPostorder() const;
    void showLeafNodes() const;
    int height();
    int depth();
    void mirall();
    void mostraRangs(int k1, int k2);
    /*Modificadors*/
    void insert(const Type& element);
private:
    int size(NodeTree<Type>* p) const;
    void showPreorder(NodeTree<Type>* p) const;
    void showPostorder(NodeTree<Type>* p) const;
    void showInorder(NodeTree<Type>* p) const;
    void showLeafNodes(NodeTree<Type>* p)const;
    void deletingNodes(NodeTree<Type>* p)const;
    void copyNodes(NodeTree<Type>* p, NodeTree<Type>* n)const;
    int height(NodeTree<Type>* p);
    int depth(NodeTree<Type>* p);
    void mirall(NodeTree<Type>* p);
    void mostraRangs(NodeTree<Type>* root, int k1, int k2);
    /*Atributs*/
    NodeTree<Type>* pRoot;
};

/* MIRALL */
template <class Type>
void BST<Type>::mirall() {
    this->showPreorder();
    cout << "Mirall " << endl;
    this->mirall(this->pRoot);
    cout << endl;
}
//La funcion lo que hace es imprimir en orden espejo, no se crea otro arbol con elementos iguales, no hace falta
template <class Type>
void BST<Type>::mirall(NodeTree<Type>* p) {
    if (p->isExternal()) {
        cout << p->getElement() << ", ";
        return;
    } else {
        cout << p->getElement() << ", ";
        if (p->hasRight())
            this->mirall(p->right());
        if (p->hasLeft())
            this->mirall(p->left());
    }
}

/* MOSTRA RANGS */

template <class Type>
void BST<Type>::mostraRangs(int k1, int k2) {
    cout << "MOSTRA RANGS" << endl;
    this->mostraRangs(this->pRoot, k1, k2);
    cout << endl;
}
//La funcion hace un inOrdre y solo cuando necesita imprimir verifica si esta en el rango o no
template <class Type>
void BST<Type>::mostraRangs(NodeTree<Type>* root, int k1, int k2) {
    if (root->isExternal()) {
        if (root->getElement() >= k1 && root->getElement() <= k2) {
            cout << root->getElement() << ", ";
        }
        return;
    } else {
        if (root->hasLeft())
            this->mostraRangs(root->left(), k1, k2);
        if (root->getElement() >= k1 && root->getElement() <= k2) {
            cout << root->getElement() << ", ";
        }
        if (root->hasRight())
            this->mostraRangs(root->right(), k1, k2);
    }
}

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
BST<Type>::~BST() {
    cout << "Destruint arbre binari" << endl;
    this->deletingNodes(this->pRoot);
    cout << "Arbre binari destruit " << endl;
}

template <class Type>
void BST<Type>::deletingNodes(NodeTree<Type>* p) const {
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
void BST<Type>::insert(const Type& element) {
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
NodeTree<Type>* BST<Type>::root() {
    return this->pRoot;
}

template <class Type>
bool BST<Type>::search(const Type& element) {
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
int BST<Type>::height() {
    if (isEmpty()) {
        return 0;
    } else {
        return this->height(this->pRoot);
    }
}

template <class Type>
int BST<Type>::height(NodeTree<Type>* p) {
    if (p == nullptr) {
        return 0;
    } else {
        return max(height(p->left()), height(p->right())) + 1;
    }
}

template <class Type>
int BST<Type>::depth() {

}

template <class Type>
int BST<Type>::depth(NodeTree<Type>* p) {
    if (p == nullptr) {
        return 0;
    } else {
        return (p->parent()) + 1;
    }
}

#endif /* BST_H */

