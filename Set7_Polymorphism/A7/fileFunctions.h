#ifndef FILEFUNCTIONS
#define FILEFUNCTIONS
#include <string>
#include <fstream>
using namespace std;

string promptUserForFileName();
bool open_file(ifstream&, const string);


#endif