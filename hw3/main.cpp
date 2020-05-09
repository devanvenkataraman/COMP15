/*
 *		main.cpp
 *		COMP15 hw4
 *
 *		Short main, just triggers the game through an instance of MetroSim
 *
 *		Author: Devan Venkataraman
 *		Date: 2/12/2019
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "MetroLine.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3 || argc > 4) {
		// fix this error message
		cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" << endl;
		exit(EXIT_FAILURE);
	}

	MetroSim simulation(argv[1], argv[2]);

	if (argc == 3) {
		simulation.runUserGame();
	}
	else {
		simulation.runFileGame(argv[3]);
	}

	return 0;
}
