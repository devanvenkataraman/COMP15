/*
 *		MetroLine.cpp
 *		COMP15 hw4
 *
 *		Implementation of MetroLine class. Handles movement of train,
 *      adding and removing passengers
 *
 *		Author: Devan Venkataraman
 *		Date: 2/12/2019
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "MetroLine.h"
#include "Passenger.h"

using namespace std;

// constructor for stations file
MetroLine::MetroLine(string inFilename, string outFilename) {
    outputFile = outFilename;
    size = 0;
    train_at = 0;
    total_passengers = 0;
    readInStations(inFilename);
}

// default constructor
MetroLine::MetroLine() {
    size = 0;
    train_at = 0;
    total_passengers = 0;
}

// destructor
MetroLine::~MetroLine() {
    while(!station_list.empty()) {
        station_list.pop_back();
    }
}

// Function readInStations
// Parameters: string filename
// Returns: void
// Does: reads in file, quits if error reading, populates station struct data
//       for all stations. Also initializes empty train vector.
void MetroLine::readInStations(string filename) {
    ifstream infile(filename.c_str());
    // Error check
    if (infile.fail()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // take in stations text file
    int station_index = 1;
    while (!infile.eof()) {
        Station station;
        station.id = station_index;
        getline(infile, station.name);
        station_list.push_back(station);
        size++;
        station_index++;
    }
    // delete extra made by 1 indexing
    size--;
    station_index--;
    // populate train vector with correct number of empty PassengerQueues
    PassengerQueue placeholder;
    for (int i = 0; i < size; i++) {
        train.push_back(placeholder);
    }
}

// Function print
// Parameters: none
// Returns: void
// Does: Prints entirety of program, uses PassengerQueue print function
//       where necessary
void  MetroLine::print() {
    cout << "Passengers on the train: {";
    // for each PassengerQueue in the train vector, print each passenger
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < train.at(i).size(); j++) {
            train.at(i).print();
        }
    }
    cout << "}" << endl;

    for (int i = 0; i < size; i++) {
        // print differently if the train is here
        if (train_at == (station_list.at(i).id - 1)) {
            cout << "TRAIN: [";
        }
        else {
            cout << "       [";
        }
        // print each passenger
        cout << station_list.at(i).id
        << "] " << station_list.at(i).name << " {";
        station_list.at(i).passengers.print();
        cout << "}" << endl;
    }
}

// Function moveTrain
// Parameters: none
// Returns: void
// Does: moves the train one stop forward. If at the last one, go back
//       to the beginning
void MetroLine::moveTrain() {
    if (train_at == (size - 1)) {
        train_at = 0;
    }
    else {
        train_at++;
    }
}

// Function boardTrain
// Parameters: none
// Returns: void
// Does: boards all awaiting passengers onto the train
void MetroLine::boardTrain() {
    int station_queue_length = station_list.at(train_at).passengers.size();
    // for each passenger waiting at the station
    for (int i = 0; i < station_queue_length; i++) {
        int destination = station_list.at(train_at).passengers.front().to;
        train[destination - 1].enqueue(station_list.at(train_at).
        passengers.front());
        // dequeue them from the station
        station_list.at(train_at).passengers.dequeue();
    }
}

// Function unloadTrain
// Parameters: none
// Returns: void
// Does: unloads passengers arriving at the station
void MetroLine::unloadTrain() {
    int station_queue_length = train.at(train_at).size();
    // for each passenger that needs to get off
    for (int i = 0; i < station_queue_length; i++) {

        printDepartingPassenger(train[train_at].front().id,
                                station_list.at(train_at).name);
        train[train_at].dequeue();
    }
}

// Function printDepartingPassenger
// Parameters: Passenger passenger, int index
// Returns: void
// Does: prints the departed passenger to outfile
void MetroLine::printDepartingPassenger(int id, string name) {
    ofstream outfile;
    outfile.open(outputFile, ios::app);
    outfile << "Passenger " << id << " left train at station "
            << name << endl;
    outfile.close();
}

// Function addAPassanger
// Parameters: none
// Returns: void
// Does: creates a new passenger and adds it to the station it's waiting from
void MetroLine::addAPassenger(int arrival, int departure) {
    total_passengers++;
    Passenger new_passenger;
    new_passenger.id = total_passengers;
    new_passenger.from = arrival;
    new_passenger.to = departure;

    station_list.at(arrival-1).passengers.enqueue(new_passenger);
}
