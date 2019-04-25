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

#include "NodeTree.h"


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
    /*Modificadors*/
    void insert(const Type& element);
private:
    int size(NodeTree<Type>* p) const;
    void showPreorder(NodeTree<Type>* p) const;
    void showPostorder(NodeTree<Type>* p) const;
    void showInorder(NodeTree<Type>* p) const;
    /*Atributs*/
    NodeTree<Type>* pRoot;
};

template <class Type>
BST<Type>::BST(){
    NodeTree<Type>* emptyRoot = new NodeTree();
    this->pRoot = emptyRoot;
}

#endif /* BST_H */

