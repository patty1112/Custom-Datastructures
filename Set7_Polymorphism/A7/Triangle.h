#ifndef TRIANGLE
#define TRIANGLE
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;


class Triangle : public ConvexShape {
    public:
    Vector2f vertex1;
    Vector2f vertex2;
    Vector2f vertex3;
   
    Triangle();
    void setColor(const Color);
    void draw(RenderTarget&);

    virtual bool setCoordinates(Vector2f&, Vector2f&, Vector2f&) = 0;
    void print();

    protected:
    int vertexCount;
    vector<Vector2f> vertexList;

    private:
    Color triangleColor;
};

#endif