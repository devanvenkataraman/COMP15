/*
 *		MetroSim.h
 *		COMP15 hw4
 *
 *		Interface of MetroSim class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/12/2019
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "MetroLine.h"

class MetroSim
{
public:
    MetroSim(string inFilename, string outFilename);
    MetroSim();
    void runUserGame();
    void runFileGame(string filename);

private:
    void takeUserQuery();
    void takeFileQuery(string filename);
    void metroMove();
    void addAPassenger(int arrival, int departure);

    MetroLine stations;
};

#endif
