#include <iostream>
#include <vector>
#include "PassengerQueue.h"

using namespace std;

// constructor
PassengerQueue::PassengerQueue() {
}

// destructor
PassengerQueue::~PassengerQueue() {
    passenger_list.clear();
}

// Function front
// Parameters: none
// Returns: Passenger
// Does: returns first passenger
Passenger PassengerQueue::front() {
    return passenger_list.at(0);
}

// Function dequeue
// Parameters: none
// Returns: void
// Does: dequeues the first passenger
void PassengerQueue::dequeue() {
    passenger_list.erase(passenger_list.begin());
}

// Function enqueue
// Parameters: Passenger
// Returns: void
// Does: adds passenger to back of list
void PassengerQueue::enqueue(const Passenger& passenger) {
    passenger_list.emplace_back(passenger);
}

// Function size
// Parameters: none
// Returns: int
// Does: returns number of passengers in the queue
int PassengerQueue::size() {
    return passenger_list.size();
}

// Function print
// Parameters: none
// Returns: void
// Does: prints all passengers information in the queue
void PassengerQueue::print() {
    int size = passenger_list.size();
    for (int i = 0; i < size; i++) {
        cout << "[" << passenger_list.at(i).id << ", "
        << passenger_list.at(i).from << "->"
        << passenger_list.at(i).to << "]";
    }
}
