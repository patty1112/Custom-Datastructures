#ifndef PITCHEROUTCOMES
#define PITCHEROUTCOMES

struct pitcherOutcomes {
    int strikeOut;              //3 possible outcomes for a missed pitch
    int walk;                   //Strike out, walk, and hitting the batter
    int hitBatter;

    pitcherOutcomes();
    pitcherOutcomes(const int&);        //Default and copy constructors
    int getStrikeOut() const;
    int getWalk() const;            //Getter for each outcome
    int getHitBatter() const;
};



#endif