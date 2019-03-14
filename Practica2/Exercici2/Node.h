/* 
 * File:   Node.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:56
 */

#ifndef NODE_H
#define	NODE_H


class Node {
public:
    Node();
    Node(int el);
    Node(const Node& orig);
    virtual ~Node();
    int getElement()const;
    Node* getNext()const;
    void setNext(Node *);
private:
    int element;
    Node next;
};

#endif	/* NODE_H */

