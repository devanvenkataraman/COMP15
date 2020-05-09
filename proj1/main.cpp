/*
 *		main.cpp
 *		COMP15 proj1 - CalcYouLater
 *
 *		Main for CalcYouLater
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

int main() {

    RPNCalc calculator;
    calculator.run();

    return 0;
}
