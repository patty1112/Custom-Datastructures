#ifndef POSITION
#define POSITION

#include <iostream>
using namespace std;

struct Position {
    int row;
    int column;

    Position();     
    Position(int, int);     //Copy constructor / Parameterized
    Position(const Position&);
    Position& operator=(const Position&);
    void print();           //Prints a position
};

Position& Position::operator=(const Position& OTHER) {
    this->row = OTHER.row;
    this->column = OTHER.column;
}

Position::Position() {      //Initialize all rows and columns to 0
    row = 0;
    column = 0;
}

Position::Position(int r, int c) {      //Make rows and columns out of given values
    row = r;
    column = c;
}

Position::Position(const Position& OTHER) {
    row = OTHER.row;
    column = OTHER.column;
}

void Position::print() {
    cout << "ROW: " << row << endl;             //Print rows and columns
    cout << "COLUMN: " << column << endl;
}
#endif