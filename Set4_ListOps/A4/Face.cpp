#include "Face.h"

Face::Face() {
    Vertex1 = 1;
    Vertex2 = 1;
    Vertex3 = 1;
}

Face::Face(int first, int second, int third) {
    Vertex1 = first;
    Vertex2 = second;
    Vertex3 = third;
}

Face::~Face() {
    
}