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
    NodeTree(Type* data, int key);
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
    Type* getValue();
    const int getKey()const;
    /*Modificadors*/
    void setRight(NodeTree<Type>* newRight);
    void setLeft(NodeTree<Type>* newLeft);
    void setParent(NodeTree<Type>* newParent);
    void setValue(Type* value);
    void setKey(int key);
private:
    NodeTree<Type>* pParent;
    NodeTree<Type>* pLeft;
    NodeTree<Type>* pRight;
    Type* value;
    int key;

};

template <class Type>
NodeTree<Type>::NodeTree(Type* data, int key) {
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->pParent = nullptr;
    this->value = data;
    this->key = key;
}

template <class Type>
NodeTree<Type>::~NodeTree() {

}

template <class Type>
NodeTree<Type>* NodeTree<Type>::right() const {
    return this->pRight;
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::left() const {
    return this->pLeft;
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::parent() const {
    return this->pParent;
}

template <class Type>
bool NodeTree<Type>::hasRight() const {
    return this->pRight != nullptr;
}

template <class Type>
bool NodeTree<Type>::hasLeft() const {
    return this->pLeft != nullptr;
}

template <class Type>
bool NodeTree<Type>::isRoot() const {
    return this->pParent == nullptr;
}

template <class Type>
bool NodeTree<Type>::isExternal() const {
    return !this->hasRight() && !this->hasLeft();
}

template <class Type>
void NodeTree<Type>::setValue(Type* value) {
    this->value = value;
}

template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft) {
    this->pLeft = newLeft;
}

template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight) {
    this->pRight = newRight;
}

template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent) {
    this->pParent = newParent;
}

template <class Type>
Type* NodeTree<Type>::getValue() {
    return this->value;
}

template <class Type>
const int NodeTree<Type>::getKey() const {
    return this->key;
}

template <class Type>
void NodeTree<Type>::setKey(int key) {
    this->key = key;
}
#endif /* NODETREE_H */

