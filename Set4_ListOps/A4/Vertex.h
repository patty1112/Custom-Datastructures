#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
private:
    
public:
    float xValue;
    float yValue;       //Holds three floats
    float zValue;
    Vertex();
    Vertex(float x, float y, float z);      //Constructors and destructor
    ~Vertex();
};


#endif