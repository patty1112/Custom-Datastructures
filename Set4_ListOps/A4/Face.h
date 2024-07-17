#ifndef FACE_H
#define FACE_H 

class Face {
    private:
    
    public:
    Face();                                 //Constructors
    Face(int first, int second, int third);
    ~Face();                                    //Destructor
    int Vertex1;
    int Vertex2;                //Holds three verticies
    int Vertex3;

};


#endif