#ifndef FILE_FUNCTIONS
#define FILE_FUNCTIONS

#include <fstream>
#include <iomanip>
#include "Field.h"

void writeField(const Field&, ofstream& fileOutput);            //Writes a whole sorted team to file
void writePlayer(const int&, ofstream& fileOutput, const Field& orderedTeam);       //Writes player to file
bool checkInput(const string&);


#endif