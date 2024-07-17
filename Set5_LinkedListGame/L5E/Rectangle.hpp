#ifndef RECTANGLE
#define RECTANGLE
#include <random>



class Rectangle {
private:
    float Length;
    float Height;
public:
    Rectangle();            //Constructor
    ~Rectangle();           //Destructor
    float getLength();
    float getHeight();
    bool operator>(const Rectangle&);
    bool operator<(const Rectangle&);
    Rectangle& operator>=(const Rectangle&);
    Rectangle& operator<=(const Rectangle&);
    void randomSides();

};


Rectangle::Rectangle() {
    Length = 1;                 //Default lengths
    Height = 1;
}


Rectangle::~Rectangle() {
    
}

float Rectangle::getHeight() {  
    return Height;
}   

float Rectangle::getLength() {
    return Length;
}

void Rectangle::randomSides() {
    int low = 1;                    //Makes int  variables for the max and min limits
    int high = 100;
    rand();                         //Discard a random value
    Length = (rand() / (float)RAND_MAX * high) + low;   //Make the length a float between the limits
    Height = (rand() / (float)RAND_MAX * high) + low;   //Make the height a float between the limits

}

bool Rectangle::operator<(const Rectangle& RHS) {   //Overload the less than operator for rectangles
    if(this->Length < RHS.Length) {         //If the length of the left is less than the right
        return this->Length < RHS.Length;                        //return true
    } else if(this->Length == RHS.Length) {     //else if they are equal,
        if(this->Height < RHS.Height) {         //compare height second, if left is less than right
            return this->Height < RHS.Height;            //return true
        }
    }
    return false;           //else return false
}

bool Rectangle::operator>(const Rectangle& RHS) {       //Overload the > operator
    if(this->Length > RHS.Length) {                 //If the length of the left is greater than the right 
        return true;                                //return true
    } else if (RHS.Length == this->Length) {        //If the lengths are equal
        if(this->Length > RHS.Length) {             //compare the height, if the left is greater than the right,
            return true;                            //Return true
        }
    }
    return false;                   //Else return false
}       

#endif