/*
 *
 *  COMP 15 proj1
 *
 *  Parser.cpp
 *  Modified By (UTLN): Devan Venkataraman
 *           On       : 02/18/2020
 *
 */
 #include <string>
 #include <iostream>
 #include <fstream>

 using namespace std;

string parseRString(istream &input);

int main() {
    string result;
    // ifstream filename("parse_test.txt");
    // result = parseRString(filename);
    result = parseRString(cin);

    cout << result << endl;

    return 0;
}

// Function parseRString
// Parameters: address of istream object
// Returns: string
// Does: Parses an input by separating according to matching curly braces
string parseRString(istream &input) {
    string parsed = "{ ";
    char append;
    int index = 1;

    // while not at the end of the input
    while(input.get(append)) {

        if (append == '{') {
            index++;
        }
        else if (append == '}') {
            index--;
        }

        parsed += append;

        // if we have matching braces
        if (index == 0) {
            break;
        }
    }
    return parsed;
}
