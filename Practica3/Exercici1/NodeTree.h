/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 25 / d’abril / 2019, 11:38
 */

#ifndef NODETREE_H
#define NODETREE_H

template <class Type>
class NodeTree {
public:
    NodeTree(const Type& data);
    NodeTree(const NodeTree& orig);
    virtual ~NodeTree(); // destructor
    /*Consultors*/
    NodeTree<Type>* right() const;
    NodeTree<Type>* left() const;
    NodeTree<Type>* parent() const;
    bool hasRight() const;
    bool hasLeft() const;
    bool isRoot() const;
    bool isExternal() const;
    const Type& getElement() const;
    /*Modificadors*/
    void
    setElement
    (const Type& data);
    void setRight(NodeTree<Type>* newRight);
    void setLeft(NodeTree<Type>* newLeft);
    void setParent(NodeTree<Type>* newParent);
private:
    NodeTree<Type>* pParent;
    NodeTree<Type>* pLeft;
    NodeTree<Type>* pRight;
    Type element;
};

template <class Type>
NodeTree<Type>::NodeTree(const Type& data) {
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->pParent = nullptr;
    this->element = data;
}

template <class Type>
NodeTree<Type>::right() const {
    return this->pRight;
}

template <class Type>
NodeTree<Type>::left() const {
    return this->pLeft;
}

template <class Type>
NodeTree<Type>::parent() const {
    return this->pParent;
}

template <class Type>
NodeTree<Type>::hasRight() const {
    return this->pRight != nullptr;
}

template <class Type>
NodeTree<Type>::hasLeft() const {
    return this->pLeft != nullptr;
}

template <class Type>
NodeTree<Type>::isRoot() const {
    return this->pParent == nullptr;
}

template <class Type>
NodeTree<Type>::isExternal() const {
    return !this->hasRight() && !this->hasLeft();
}

template <class Type>
NodeTree<Type>::setElement(const Type& data) {
    this->element = data;
}

template <class Type>
NodeTree<Type>::setLeft(NodeTree<Type>* newLeft) {
    this->pLeft = newLeft;
}

template <class Type>
NodeTree<Type>::setRight(NodeTree<Type>* newRight) {
    this->pRight = newRight;
}

template <class Type>
NodeTree<Type>::setParent(NodeTree<Type>* newParent) {
    this->pParent = newParent;
}

#endif /* NODETREE_H */

