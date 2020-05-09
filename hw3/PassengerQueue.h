#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include <vector>
#include "Passenger.h"

using namespace std;

class PassengerQueue
{
public:
    PassengerQueue();
    ~PassengerQueue();
    Passenger front();
    void dequeue();
    void enqueue(const Passenger& passenger);
    int size();
    void print();

private:
    vector <Passenger> passenger_list;
};

#endif
