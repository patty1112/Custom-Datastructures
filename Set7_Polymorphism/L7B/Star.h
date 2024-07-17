#ifndef STAR
#define STAR
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Star : public CircleShape{
private:
    int windowWidth;
    int windowHeight;
    float starBrightness;

public:
    

    Star();
    Star(int, int, float);
    ~Star();
    void setWidth();
    void setHeight();
    void setPosition(float, float);
    void setBrightness(float);
};


#endif