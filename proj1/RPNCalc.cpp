/*
 *		RPNCalc.cpp
 *		COMP15 proj1
 *
 *		Implementation of RPNCalc class
 *
 *		Author: Devan Venkataraman
 *		Date: 2/26/2019
 */

#include "Datum.h"
#include "RPNCalc.h"
#include "DatumStack.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// default constuctor
RPNCalc::RPNCalc() {
    // initialize any private data members
}

// destructor
RPNCalc::~RPNCalc() {
    // delete any heap-allocated data
}

// Function run
// Parameters: none
// Returns: void
// Does: Initiates calculator by calling for query fielding
void RPNCalc::run() {
    fieldQuery();
    cout << "Thank you for using CalcYouLater." << endl;
}

// Function fieldQuery
// Parameters: none
// Returns: void
// Does: Fields queries from cin
void RPNCalc::fieldQuery() {

    string input;

    while (cin >> input) {

        if (input == "{") {
            string r_string = parseRString(cin);
            the_stack.push(Datum(r_string));
        }
        else if (input == "quit") {
            return;
        }
        else {
            fieldMostQueries(input);
        }

        if (game_on == false) {
            return;
        }
    }
}

// Function fieldQuery
// Parameters: istringstream
// Returns: void
// Does: Fields queries from a string stream
void RPNCalc::fieldQuery(istringstream &iss) {

    string input;

    while (iss >> input) {

        if (input == "{") {
            string r_string = parseRString(iss);
            the_stack.push(Datum(r_string));
        }
        else if (input == "quit") {
            game_on = false;
            return;
        }
        else {
            fieldMostQueries(input);
        }
        if (game_on == false) {
            return;
        }
    }
}

// Function fieldQuery
// Parameters: ifstream
// Returns: void
// Does: Fields queries from file stream
void RPNCalc::fieldQuery(ifstream &ifs) {

    string input;

    while (ifs >> input) {

        if (input == "{") {
            string r_string = parseRString(ifs);
            the_stack.push(Datum(r_string));
        }
        else if (input == "quit") {
            game_on = false;
            return;
        }
        else {
            fieldMostQueries(input);
        }
        if (game_on == false) {
            return;
        }
    }
}

// Function fieldMostQueries
// Parameters: string input
// Returns: void
// Does: Performs most queries that are independent of the input source;
//       calls function containing other queries if not found here.
void RPNCalc::fieldMostQueries(string input) {
    if (testInt(input)) {
    }
    else if (input == "#t" or input == "#f") {
        pushBool(input);
    }
    else if (input == "print") {
        try {
            print();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "not") {
        try {
            flipBool();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "clear") {
        the_stack.clear();
    }
    else if (input == "drop") {
        try {
            the_stack.pop();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else {
        fieldMostQueries2(input);
    }
}

// Function fieldMostQueries2
// Parameters: string input
// Returns: void
// Does: Checks other queries that are independent of the input source;
//       calls function containing remaining queries if not found here.
void RPNCalc::fieldMostQueries2(string input) {
    if (input == "dup") {
        try {
            duplicate();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "swap") {
        try {
            swap();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "+" or input == "-"
             or input == "*" or input == "/" or input == "mod") {
        try {
            operate(input);
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "<" or input == ">"
             or input == "<=" or input == ">=" or input == "==") {
        try {
            comparison(input);
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else {
        fieldMostQueries3(input);
    }
}

// Function fieldMostQueries3
// Parameters: string input
// Returns: void
// Does: Checks remaining queries that are independent of the input source;
//       If not found, cerr unimplemented as it is an invalid command.
void RPNCalc::fieldMostQueries3(string input) {
    if (input == "exec") {
        try {
            exec();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "file") {
        try {
            file();
        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    else if (input == "if") {
        doIf();
    }
    else {
        cerr << input << ":  unimplemented" << endl;
    }
}

// Function pushBool
// Parameters: string input
// Returns: void
// Does: Pushes a bool value onto the stack
void RPNCalc::pushBool(string input) {
    if (input == "#t") {
        the_stack.push(Datum(true));
    }
    else {
        the_stack.push(Datum(false));
    }
}

// Function print
// Parameters: none
// Returns: void
// Does: prints Datum on top of stack, throws exception if empty
void RPNCalc::print() {
    cout << the_stack.top().toString() << endl;
}

// Function flipBool
// Parameters: none
// Returns: void
// Does: Flips boolean value on top of stack; throws exception if empty
void RPNCalc::flipBool() {

    bool temp = the_stack.top().getBool();
    the_stack.pop();
    the_stack.push(Datum(!temp));
}

// Function testInt
// Parameters: string input
// Returns: bool
// Does: Tests if the input is an int. If it is, push it on the stack
//       and return true (command handled), return false otherwise
bool RPNCalc::testInt(string input) {
    int to_add = 0;

    if (got_int(input, &to_add)) {
        the_stack.push(Datum(to_add));
        return true;
    }
    else {
        return false;
    }
}

// Function duplicate
// Parameters: none
// Returns: void
// Does: Duplicates the Datum on top of the stack, pushing it. Throws
//       exception if empty
void RPNCalc::duplicate() {
    the_stack.push(Datum(the_stack.top()));
}

// Function swap
// Parameters: none
// Returns: void
// Does: Takes the top two Datum on the stack and swaps. Throws exception
//       if not at least two Datum on the stack
void RPNCalc::swap() {

    Datum temp1 = the_stack.top();
    the_stack.pop();
    Datum temp2 = the_stack.top();
    the_stack.pop();

    the_stack.push(temp1);
    the_stack.push(temp2);

}

// Function operate
// Parameters: string input
// Returns: void
// Does: Performs the operation command provided on the top two Datum
//       on the stack. Throws exception if not enough Datum on stack
//       or if not of valid Datum type
void RPNCalc::operate(string input) {
    // Store the top two Datum in temps and pop them
    Datum temp1 = the_stack.top();
    the_stack.pop();
    Datum temp2 = the_stack.top();
    the_stack.pop();
    // perform the operation, push the result
    if (input == "+") {
        int new_int = temp2.getInt() + temp1.getInt();
        the_stack.push(Datum(new_int));
    }
    else if (input == "-") {
        int new_int = temp2.getInt() - temp1.getInt();
        the_stack.push(Datum(new_int));
    }
    else if (input == "*") {
        int new_int = temp2.getInt() * temp1.getInt();
        the_stack.push(Datum(new_int));
    }
    else if (input == "/") {
        int new_int = temp2.getInt() / temp1.getInt();
        the_stack.push(Datum(new_int));
    }
    else if (input == "mod") {
        int new_int = temp2.getInt() % temp1.getInt();
        the_stack.push(Datum(new_int));
    }
}

// Function comparison
// Parameters: string input
// Returns: void
// Does: Performs the comparison command provided on the top two Datum
//       on the stack. Throws exception if not enough Datum on stack
//       or if not of valid Datum type
void RPNCalc::comparison(string input) {
    // Store the top two Datum in temps and pop them
    Datum temp1 = the_stack.top();
    the_stack.pop();
    Datum temp2 = the_stack.top();
    the_stack.pop();

    // perform the comparison, push the result
    if (input == "<") {
        the_stack.push(Datum(temp2 < temp1));
    }
    else if (input == ">") {
        the_stack.push(Datum(temp1 < temp2));
    }
    else if (input == "<=") {
        bool result = (temp2 < temp1) or (temp2 == temp1);
        the_stack.push(Datum(result));
    }
    else if (input == ">=") {
        bool result = (temp1 < temp2) or (temp2 == temp1);
        the_stack.push(Datum(result));
    }
    else if (input == "==") {
        the_stack.push(Datum(temp2 == temp1));
    }
}

// Function exec
// Parameters: none
// Returns: void
// Does: Executes the rString on the top of the stack. Throws error if
//       top of stack is not an rString or if it's empty
void RPNCalc::exec() {
    if (!the_stack.top().isRString()) {
        cerr << "Error: cannot execute non rstring" << endl;
        return;
    }
    // convert top Datum to a string
    string to_exec = the_stack.top().toString();
    // drop the braces off the string, pop it off the stack
    string ready_to_exec = dropBraces(to_exec);
    the_stack.pop();
    // create a string stream and field the queries from the string stream
    istringstream iss(ready_to_exec);
    fieldQuery(iss);
}

// Function dropBraces
// Parameters: string input
// Returns: string
// Does: Helper function that drops the outermost braces and spaces
//       from the rString
string RPNCalc::dropBraces(string input) {
    input.pop_back();
    input.pop_back();
    input.erase(input.begin());
    input.erase(input.begin());

    return input;
}

// Function file
// Parameters: none
// Returns: void
// Does: takes in the filename specified on top of the stack as rString.
//       Takes commands from the specified file
void RPNCalc::file() {

    if (!the_stack.top().isRString()) {
        cerr << "Error: file operand not rstring" << endl;
        return;
    }
    // take in file name and pop it
    string the_file = the_stack.top().toString();
    the_stack.pop();
    // drop the braces and create ifstream
    the_file = dropBraces(the_file);
    ifstream ifs(the_file.c_str());

    if (ifs.fail()) {
        cerr << "Unable to read " << the_file << endl;
        return;
    }

    // field the queries from the ifstream
    fieldQuery(ifs);
}

// Function doIf
// Parameters: none
// Returns: void
// Does: Handles the if command. Throws error if any Datum of not correct
//       type.
void RPNCalc::doIf() {
    // Check that each Datum on the stack is of the correct type. Store
    // each as the false case, true case, and condition respectively. Pop them.
    if (!the_stack.top().isRString()) {
        cerr << "Error: expected rstring in if branch" << endl;
        return;
    }
    string false_case = the_stack.top().getRString();
    the_stack.pop();
    if (!the_stack.top().isRString()) {
        cerr << "Error: expected rstring in if branch" << endl;
        return;
    }
    string true_case = the_stack.top().getRString();
    the_stack.pop();
    if (!the_stack.top().isBool()) {
        cerr << "Error: expected boolean in if test" << endl;
        return;
    }
    bool condition = the_stack.top().getBool();
    the_stack.pop();
    // if condition true, push + execute true case, push + exec false otherwise
    if (condition) {
        the_stack.push(Datum(true_case));
    }
    // else, push and execute the false case
    else {
        the_stack.push(Datum(false_case));
    }
    exec();
}

// --------- Function they gave us ---------
// Function got_int
// Parameters: string s, pointer to an int
// Returns: bool
// Does: Scans the string parameter to detect if it is an int. If it is,
//       update the referenced int passed as parameter. Return true if it's
//       an int, false otherwise
bool RPNCalc::got_int(string s, int *resultp) {
    return sscanf(s.c_str(), "%d", resultp) == 1;
}

// --------- My parse function from part 1 ---------
// Function parseRString
// Parameters: address of istream object
// Returns: string
// Does: Parses an input by separating according to matching curly braces.
//       Returns the parsed string
string RPNCalc::parseRString(istream &input) {
    string parsed = "{";
    string append;
    int index = 1;

    // while not at the end of the input
    while((append != "}") or (index > 0)) {

        input >> append;

        if (append == "{") {
            index++;
        }
        else if (append == "}") {
            index--;
        }

        parsed = parsed + " " + append;
    }
    return parsed;
}
