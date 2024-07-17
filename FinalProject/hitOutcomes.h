#ifndef HITOUTCOMES
#define HITOUTCOMES

struct hitOutcomes {        //Each different outcome for a hit.
    int out;                //Corresponds to 1
    int single;             //Corresponds to 2
    int _double;            //Corresponds to 3
    int triple;             //Corresponds to 4
    int HR;                 //Corresponds to 5
    int IPHR;               //Corresponds to 6

    hitOutcomes();              //Defult and copy constructor
    hitOutcomes(const int&);
    int getOut() const;
    int getSingle() const;          //Getters for the ranges
    int getDouble() const;
    int getTriple() const;
    int getHR() const;
    int getIPHR() const;

};


#endif