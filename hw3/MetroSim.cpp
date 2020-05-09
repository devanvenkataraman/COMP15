/*
 *		MetroSim.cpp
 *		COMP15 hw4
 *
 *		Implementation of MetroSim class. Handles getting queries,
 *      triggering actions in MetroLine class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/12/2019
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "MetroSim.h"
#include "MetroLine.h"
#include "PassengerQueue.h"
#include "string"

// constructor
MetroSim::MetroSim(string inFilename, string outFilename) {
    MetroLine metro(inFilename, outFilename);
    stations = metro;
}

// default constructor
MetroSim::MetroSim() {
    MetroLine metro;
}

// Function runUserGame
// Parameters: none
// Returns: void
// Does: calls testQuery function
void MetroSim::runUserGame() {
    takeUserQuery();
}

// Function runFileGame
// Parameters: none
// Returns: void
// Does: calls testQuery function
void MetroSim::runFileGame(string filename) {
    takeFileQuery(filename);
}

// Function takeUserQuery
// Parameters: none
// Returns: void
// Does: takes in user input and triggers queries
void MetroSim::takeUserQuery() {

    bool play_game = true;

    while (play_game == true) {
        stations.print();
        cout << "Command? ";
        // set initial argument values so we can test if 2 or 3 specified
        string arg1 = "0", arg2 = "00", arg3 = "000";
        string input;
        getline(cin, input);
        stringstream ss(input);

        // take in command and max of three args
        ss >> arg1 >> arg2 >> arg3;

        if (arg1 == "m" and arg2 == "m") {
            metroMove();
        }
        else if (arg1 == "m" and arg2 == "f") {
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            play_game = false;
            break;
        }
        else if (arg3 != "000") {
            int arrival = stoi(arg2);
            int departure = stoi(arg3);
            addAPassenger(arrival, departure);
        }
    }
}

// Function takeFileQuery
// Parameters: none
// Returns: void
// Does: takes in command file input and triggers queries
void MetroSim::takeFileQuery(string filename) {

    ifstream infile;
    infile.open(filename);
    // Error check
    if (infile.fail()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    bool play_game = true;

    while (play_game == true) {
        while (!infile.eof()) {
            stations.print();
            cout << "Command? ";
            // set initial argument values so we can test if 2 or 3 specified
            string arg1 = "0", arg2 = "00", arg3 = "000";
            string input;
            getline(infile, input);

            istringstream ss(input);

            // take in command and max of three args
            ss >> arg1 >> arg2 >> arg3;

            if (arg1 == "m" and arg2 == "m") {
                metroMove();
            }
            else if (arg1 == "m" and arg2 == "f") {
                cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                play_game = false;
                break;
            }
            else if (arg3 != "000") {
                int arrival = stoi(arg2);
                int departure = stoi(arg3);
                addAPassenger(arrival, departure);
            }
        }
    }
}

// Function metroMove
// Parameters: none
// Returns: void
// Does: unloads the train's passengers, boards the new ones, moves the train
void MetroSim::metroMove() {
    stations.boardTrain();
    stations.moveTrain();
    stations.unloadTrain();
}

// Function addAPassenger
// Parameters: int arrival, int departure
// Returns: void
// Does: calls MetroLine add passenger function
void MetroSim::addAPassenger(int arrival, int departure) {
    stations.addAPassenger(arrival, departure);
}
