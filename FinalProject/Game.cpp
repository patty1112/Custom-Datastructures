/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "Game.h"
#include "baseStatus.h"

void playGame(const Field& homeTeam, const Field& awayTeam) {
    int homeScore = 0;
    int awayScore = 0;
    
    unsigned int inning = 1;
    Field battingTeam = awayTeam;                   //Makes a field from the away team as the batting team
    Field fieldingTeam = homeTeam;                  //Makes a field from the home team as the fielding team
    battingTeam.setCurrentBatter(1);                //Sets the current batter for both teams
    fieldingTeam.setCurrentBatter(1);
    cout << endl;
    while(inning < 10) {                    //While the inning is less than 10
        cout << endl;
        cout << "Starting inning #" << inning << ": " << endl;      //Print the inning and score
        cout << "Home team has " << homeScore << " runs, away team has " << awayScore << " runs." << endl;
        
        battingTeam = awayTeam;         //Set the home and away team to respective sides
        fieldingTeam = homeTeam;

        cout << "Away team is up to bat." << endl;
        cout << endl;
        awayScore += playHalf(fieldingTeam, battingTeam);       //Play a half with away team batting, returns number scored
        battingTeam = homeTeam;     //Switch the teams, now home team bats
        fieldingTeam = awayTeam;
        cout << endl;
        cout << "Half inning started, home team is up to bat. +++++++++++++++++++++++++++++++++" << endl;       //Cout the score
        cout << "Home team has " << homeScore << " runs, away team has " << awayScore << " runs." << endl;
        
        cout << endl;
        homeScore += playHalf(fieldingTeam, battingTeam);       //Play the other half of the inning, returns number scored
        inning += 1;
        cout << endl;
    }
    if(homeScore > awayScore) {     //After 9 innnings, print the result
        cout << "Home team wins! The final score is " << homeScore << " runs to " << awayScore << " runs." << endl;
    } else if(homeScore < awayScore) {
        cout << "Away team wins! The final score is " << awayScore << " runs to " << homeScore << " runs." << endl;
    } else if(homeScore == awayScore) {
        cout << "The teams tied after 9 innings. The final score is " << homeScore << " runs to " << awayScore << " runs." << endl;
    }
}


int playHalf(const Field& fieldingTeam, Field& battingTeam) {       //Plays the half inning
    int outs = 0;
    int numberScored = 0;
    baseStatus baseStatus;

    

    while(outs < 3) {               //While there are less than 3 outs
        cout << "There are " << outs << " outs, " << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " is up to bat." << endl;
        cout << "There are " << baseStatus.runnersOn() << " runners on base." << endl;      //Print the number of outs and players on base
        int hitStat = battingTeam.getPlayer(battingTeam.getBatterUp()).getHitting();        //Gets the current batters hitting
        int pitchStat = fieldingTeam.getPlayer(1).getArmStrength();         //Gets the pitchers pitching stat
        float hitProbabilty = float(hitStat) / (2 * pitchStat);         //Makes the probability of a hit based on stats
        //Equal stats have 50/50 probability, if pitcher is better then less than 1/2
        int outcome = decideOutcome(hitProbabilty);     //Decides the potential outcome based off the probability
        bool hit = decideHit(hitProbabilty);            //determines if they hit the ball based on the probability
        
    
        hitOutcomes currentOutcome(outcome);            //Makes a hit outcome from the potential outcome
        pitcherOutcomes currentPitcherOutcome(outcome);     //Makes a pitcher outcome from the potential outcome
        int actualOutcome = 0;                              //Makes a variable for what actually happens
        if(hit) {           //If they hit it,
            actualOutcome = battingTeam.hitBall(currentOutcome);    //Hit the ball based on the outcome
        } else {
            actualOutcome = battingTeam.lastPitch(currentPitcherOutcome);   //Decide the pitch outcome if not hit
        }

        if(hit) {       //If hit,
            if(actualOutcome == 1) {        //If there was a field out
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " is out due to a field play!" << endl;   //Print the result
                numberScored += baseStatus.movePlayers(1, hit, numberScored);   //Move the players no bases
                outs += 1;
            } else if(actualOutcome == 2) {     //If there was a single
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " hit a single!" << endl;
                numberScored += baseStatus.movePlayers(2, hit, numberScored);
                                                //Move players 1 base ahead
            } else if(actualOutcome == 3) { //If there was a double
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " hit a double!" << endl;
                numberScored += baseStatus.movePlayers(3, hit, numberScored);
                                                //Move all players 2 bases
            } else if(actualOutcome == 4) {     //If there was a triples
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " hit a triple!" << endl;
                numberScored += baseStatus.movePlayers(4, hit, numberScored);
                                                //Move all players 3 bases
            } else if(actualOutcome == 5) {     //If there was a home run
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " hit a home run!!!" << endl;
                numberScored += baseStatus.movePlayers(5, hit, numberScored);
                                                //Score all players on base including the hitter
            } else if(actualOutcome == 6) {     //If there was a inside the park home run
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " hit an inside the park home run!!!" << endl;
                numberScored += baseStatus.movePlayers(6, hit, numberScored);
            } else {        //else there was an error
                cerr << "There was an error with the hit outcome." << endl;
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << endl;
                cout << "Outcome: " << outcome << endl;
                cout << "Actual outcome: " << actualOutcome << endl;
                cout << "Hit probability: " << hitProbabilty << endl;
            }   
        } else if(!hit) {           //If not hit,
            if(actualOutcome == 1) {        //If they strike out
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " strikes out!" << endl << endl;
                outs += 1;      //Increase the outs
            } else if(actualOutcome == 2) {     //If they walk
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " walked and is on first base." << endl;
                numberScored += baseStatus.movePlayers(2, hit, numberScored);
                                        //Move player to first, if occupied move others
            } else if(actualOutcome == 3) {     //If they get hit by the pitch
                cout << battingTeam.getPlayer(battingTeam.getBatterUp()).getName() << " got hit by pitch and is on first base." << endl;
                numberScored += baseStatus.movePlayers(3, hit, numberScored);       //Move players over
            } else {
                cerr << "There was an error with the pitch outcome." << endl << endl;       //Else there was an error
            }
        }
        battingTeam.nextBatter();       //move to the next batter
        if(outs == 3) {         //Extra break condition
            cout << "The half inning ended and " <<  numberScored << " runners scored. ----------------------------------" << endl;
            return numberScored;
        }
    }
    
    return numberScored;        //Return the number of players scored
}

int decideOutcome(const float& hitProbability) {        //Decides predicted outcome
    if(hitProbability > .9) {           //If they are likely to hit it
        return 3;                       //Good outcome
    } else if(hitProbability > .5) {    //If medium chance
        return 2;                       //Decent outcome
    }else if(hitProbability > .2) {     //If bad chance
        return 1;                       //Bad outcome
    } else {                            //Else 
        return 0;                       //terrible outcome
    }
}

bool decideHit(float hitProbability) {          //Decides if they hit it
    Dice newDice;
    int hitLimit = int(hitProbability * 100);           //range for hits is the probability*100
    newDice.rollDice();
    if(newDice.getRoll() < hitLimit) {                  //If the dice roll was less than the hit limit
        cout << "The player hit the ball!" << endl;     //They hit the ball
        return true;
    } else {            //Else they didn't hit it
        cout << "The player did not hit the ball." << endl;
        return false;
    }
}