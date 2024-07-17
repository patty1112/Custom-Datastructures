/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "fileFunctions.h"

void writePlayer(const int& position, ofstream& fileOutput, const Field& orderedTeam) {
    fileOutput << orderedTeam.getPlayer(position).getName() << ": ";                //Output each data member in order, formatted in columns
    fileOutput << setw(13) <<  "ArmStrength-" << orderedTeam.getPlayer(position).getArmStrength() << " ";   //Each is separated by a space
    fileOutput << setw(8) << "Speed-" << orderedTeam.getPlayer(position).getSpeed() << " ";
    fileOutput << setw(10) << "Agiliy-" << orderedTeam.getPlayer(position).getAgility() << " ";
    fileOutput << setw(17) << "GroundFielding-" << orderedTeam.getPlayer(position).getGroundRating() << " ";
    fileOutput << setw(19) << "FlyBallFielding-" << orderedTeam.getPlayer(position).getFlyRating() << " ";
    fileOutput << setw(11) << "Stamina-" << orderedTeam.getPlayer(position).getStamina() << " ";
    fileOutput << setw(11) << "Hitting-" << orderedTeam.getPlayer(position).getHitting() << " ";
    fileOutput << endl;
}


void writeField(const Field& orderedTeam, ofstream& fileOutput) {
    fileOutput << setw(15) << "(Pitcher) ";     //Writes the pitcher to the file using above function
    writePlayer(1, fileOutput, orderedTeam);
    
    fileOutput << setw(15) << "(Catcher) ";     //Writes the catcher to the file using above function
    writePlayer(2, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(1st Base) ";    //Writes the first baseman to the file using above function
    writePlayer(3, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(2nd Base) ";    //Writes the second baseman to the file using above function
    writePlayer(4, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(3rd Base) ";    //Writes the third baseman to the file using above function
    writePlayer(5, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(Short Stop) ";  //Writes the shortStop to the file using above function
    writePlayer(6, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(Left Field) ";  //Writes the left field to the file using above function
    writePlayer(7, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(Center Field) ";    //Writes the center field to the file using above function
    writePlayer(8, fileOutput, orderedTeam);

    fileOutput << setw(15) << "(Right Field) ";     //Writes the right field to the file using above function
    writePlayer(9, fileOutput, orderedTeam);
}

bool checkInput(const string& userInput) {  //Checks if entered stat is between 10-99
    if(userInput.length() >= 3) {       //If length is 3, prompt again
        return false;
    } else if(userInput.length() < 2) {     //If length is 0 or 1, prompt again
        return false;
    }
    for(int i = 0; i < userInput.length(); i++) {       //For each character in the input
        if(!isdigit(userInput[i])) {        //If the character is not a digit
            return false;                   //Reprompt
        }
    }
    return true;        //Else input is valid
}