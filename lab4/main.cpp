//
//  main driver:  Creates a maze and solves it.
//
//
//  Submitted by Devan Venkataraman

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "maze.h"

using namespace std;

void solveAndCount(int size);
int  getMazeSize();

int main()
{
    int size;

    cout << "MAZE CREATOR and SOLVER\n\n";
    size = getMazeSize();
    Maze maze1(size);

    // print original maze
    cout << "HERE IS YOUR MAZE: \n\n";
    maze1.print();

    // Solve and print maze
    maze1.solve();
    cout << "Your Recursive solution:\n\n";
    maze1.print();

    cout << "The calculated path length is: "<< maze1.path_length()
         << endl << endl;

    // This time, solve the maze and keep track of the path length

    Maze maze2(size);
    cout << "New maze of the same size" << endl << endl;
    maze2.print();

    int pathLength = maze2.solve_and_count();
    cout << "Solved in " << pathLength << " steps: " << endl << endl;
    maze2.print();

    return 0;
}


/*
 * Asks user for and returns a maze size.
 *
 * It would be nice if the maze size were meaningful.
 * One day, I'll get a better maze generator.
 * For now, it wants a number, and it wants to use a square matrix
 * (2 * size) + 1 on a side.  With a border all around, that means
 * the maze area is (2 * size) - 1 square.
 */
int getMazeSize()
{
    string prompt = "Pick maze size in [2 .. 30]\n"
                    "Maze will be (2 * size) - 1 on a side:  ";
    int    mazeSize = -1;
    string restOfLine;

    //
    // As long as input is invalid and we haven't reached EOF
    //
    while (not cin.fail() and (mazeSize < 2 or mazeSize > 30)) {
        cout << prompt;
        cin  >> mazeSize;
        getline(cin, restOfLine);
    }
    if (cin.fail())
        exit(1);     // They must have given up --- leave the program

    return mazeSize;
}
