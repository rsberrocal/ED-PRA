/* 
 * File:   FlightNode.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:56
 */

#ifndef NODE_H
#define NODE_H

#include <cstddef>

#include "Flight.h"

class FlightNode {
public:
    FlightNode();
    FlightNode(const Flight el);
    FlightNode(const FlightNode& orig);
    virtual ~FlightNode();
    Flight getElement()const;
    FlightNode* getNext()const;
    void setNext(FlightNode *n);
    void printNode()const;
private:
    Flight element;
    FlightNode* next;
};
#endif /* NODE_H */

