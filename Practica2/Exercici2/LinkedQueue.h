/* 
 * File:   LinkedQueue.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:44
 */

#ifndef LINKEDQUEUE_H
#define	LINKEDQUEUE_H

#include "Node.h"

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(const int key);
    void dequeue();
    bool isEmpty();
    void print();
    const int getFront();
    
private:
    int _size;
    Node* _front;
    Node* _rear;
};

#endif	/* LINKEDQUEUE_H */

