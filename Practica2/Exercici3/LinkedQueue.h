/* 
 * File:   LinkedQueue.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:44
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>

#include "FlightNode.h"
using namespace std;

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(Flight* key);
    void dequeue();
    bool isEmpty();
    void print();
    const FlightNode* getFront();

private:
    int _size;
    FlightNode* _front;
    FlightNode* _rear;
};

#endif /* LINKEDQUEUE_H */

