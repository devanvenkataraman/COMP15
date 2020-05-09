/*
 *		MetroLine.h
 *		COMP15 hw4
 *
 *		Interface of MetroLine class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/12/2019
 */

#ifndef METRO_LINE_H
#define METRO_LINE_H

#include <string>
#include "PassengerQueue.h"
#include <vector>

using namespace std;

class MetroLine {
public:
    MetroLine(string inFilename, string outFilename);
    MetroLine();
    ~MetroLine();
    void readInStations(string filename);
    void print();
    void moveTrain();
    void boardTrain();
    void unloadTrain();
    void addAPassenger(int arrival, int departure);
    void printDepartingPassenger(int id, string name);

private:
    struct Station {
        int id;
        string name;
        PassengerQueue passengers;
    };

    string outputFile;

    // train is a vector of PassengerQueues
    vector<PassengerQueue> train;

    // stations are held as a vector of station structs
    vector <Station> station_list;

    int train_at;
    int size;
    int total_passengers;

};

#endif
