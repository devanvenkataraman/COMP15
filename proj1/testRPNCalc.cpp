/*
 *		testDatumStack.cpp
 *		COMP15 proj1 - CalcYouLater
 *
 *		Essentially Unused Test file for RPNCalc Class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/26/2019
 */

#include <string>
#include <iostream>
#include <sstream>
#include "DatumStack.h"
#include "Datum.h"
#include "RPNCalc.h"

using namespace std;

// All tests were performed via .cylc files rather than test functions.
// This testRPNCalc.cpp file was used ONLY INITIALLY to ensure that an
// RPNCalc instance could be created and used to call run function.
// ALL COMMANDS AND FUNCTIONALITY was tested via the provided .cylc files.
// Further explained in README.
int main() {

    RPNCalc calculator;
    calculator.run();

    return 0;
}
