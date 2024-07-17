#ifndef VECTOR_FUNCTIONS_H
#define VECTOR_FUNCTIONS_H
#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "Vertex.h"
#include "Face.h"
using namespace std;
string promptUserForFileName();
bool open_file(ifstream&, const string);
void read_file_contents(ifstream&, LinkedList<string>&, LinkedList<Vertex>&, LinkedList<Face>&); 
bool validate_faces(LinkedList<string>&, LinkedList<Vertex>&, LinkedList<Face>&);
bool fileFunctions(LinkedList<string>&, LinkedList<Vertex>&, LinkedList<Face>&);



#endif