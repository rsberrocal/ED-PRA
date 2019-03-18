/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.h
 * Author: Rocho
 *
 * Created on 17 de marzo de 2019, 13:44
 */

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>


using namespace std;

class Flight {
public:
    Flight();
    Flight(const string id, const string from, const string to, const string time);
    Flight(const Flight& orig);
    virtual ~Flight();
    string getId()const;
    string getFrom()const;
    string getTo()const;
    string getTime()const;
    void setId(const string id);
    void setFrom(const string from);
    void setTo(const string to);
    void setTime(const string time);
private:
    string _id;
    string _from;
    string _to;
    string _time;
};

#endif /* FLIGHT_H */

