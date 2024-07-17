/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "Team.h"
Team::Team() {
    score = 0;          //Initiailizes score as 0
}

DoublyLinkedList<Player> Team::getTeamList() const {
    return teamList;            //Returns the linked list
}

Team::Team(const DoublyLinkedList<Player>& playerList) {
    teamList = playerList;          //Sets the list as playerList's list
    score = 0;                      //Score is 0, (new team)
}

void Team::assignPlayers() {
    for(int i = 1; i <= teamList.size(); i++) {     //For each player in the list
        teamList.at(i).setName(to_string(i));       //Add the number to their name
    }
}

void Team::setTeamList(const DoublyLinkedList<Player>& playerList) {
    teamList = playerList;          //Sets the team list as playerList's list
    score = 0;                      //new team score is 0
}

void Team::printTeam() {
    for(int i = 0; i < teamList.size(); i++) {      //For each player in the list
        teamList.at(i).print();                         //Print the player
    }
}

void Team::assignPositions(DoublyLinkedList<Player>& assignedPlayers, Field& playerLocations) {
    for(int i = 0; i < 9; i++) {          //for each player in the team
        if(i == 0) {        //Assign the pitcher, find largest armstrength
            int maxArm = teamList.at(0).getArmStrength();       //Make variable for the max
            int positionOfMax = 0;                              //Make variable for the position
            teamList.assignTail();                              //Make sure the tail is in the right place
            for(int j = 0; j < teamList.size(); j++) {          //For each player in the list
                if(teamList.at(j).getArmStrength() > maxArm) {      //If their stats are greater than the max
                    maxArm = teamList.at(j).getArmStrength();       //They are the max
                    positionOfMax = j;
                }
            }
            playerLocations.setPitcher(teamList.at(positionOfMax));     //Set this player as the pitcher
            assignedPlayers.insert(i, teamList.at(positionOfMax));     //Insert the player in the list of assigned players
            teamList.remove(positionOfMax);                             //Removes him from the list, 1 player to a position


        } else if(i == 1) {         //Assign the next MOST IMPORTANT POSITION BASED ON STATS
            int maxFly = teamList.at(0).getFlyRating();     //Left field is second most important
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {          //For each player in the list
                if(teamList.at(j).getFlyRating() > maxFly) {        //If they are better at left field
                    maxFly = teamList.at(j).getFlyRating();         //Set them as left field
                    positionOfMax = j;
                }
            }
            playerLocations.setLeftField(teamList.at(positionOfMax));       //Makes left field the highest fly stat
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Inserts them into the assigned players list
            teamList.remove(positionOfMax);                                 //Removes them from the list
            teamList.assignTail();                                          //Assigns the tail
        } else if(i == 2) {     //Assign the third MOST IMPORTANT POSITION
            int maxAgility = teamList.at(0).getAgility();     //Short stop is third most important
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {              //For all players in the list
                if(teamList.at(j).getAgility() > maxAgility) {      //If they are more agile
                    maxAgility = teamList.at(j).getAgility();   
                    positionOfMax = j;                              //Mark them as the most agiles
                }
            }
            playerLocations.setShortStop(teamList.at(positionOfMax));       //Sets the short stop as the highest agility
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Inserts them to the assigned players list
            teamList.remove(positionOfMax);                                 //Removes them from the list
            teamList.assignTail();                                          //Assigns the tail
        } else if(i == 3) {                         //Assign the third MOST IMPORTANT position
            int maxSpeed = teamList.at(0).getSpeed();     //Center field is third most important
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {      //For each player in the list
                if(teamList.at(j).getSpeed() > maxSpeed) {      //If they are faster
                    maxSpeed = teamList.at(j).getSpeed();       //Then they are the fastest
                    positionOfMax = j;
                }
            }
            playerLocations.setCenterField(teamList.at(positionOfMax));     //Set center field as the fastest
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Inserts the player into the assigned players
            teamList.remove(positionOfMax);                                 //Remove that player from original list
            teamList.assignTail();
        } else if(i == 4) {         //Assign the 5th MOST IMPORTANT position 3rd base
            int maxArm = teamList.at(0).getArmStrength();       //Arm strength is important
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {          //For each player in the list
                if(teamList.at(j).getArmStrength() > maxArm) {      //If they are stronger
                    maxArm = teamList.at(j).getArmStrength();       //They are the strongest
                    positionOfMax = j;
                }
            }
            playerLocations.setThirdBase(teamList.at(positionOfMax));       //Set this player as 3rd base
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Insert them into the assigned players
            teamList.remove(positionOfMax);                                 //Remove them from the list
            teamList.assignTail();
        } else if(i == 5) {             //Assign the sixth most important position
            int maxGround = teamList.at(0).getGroundRating();       //Gets the ground fielding of first player
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {              //For each player in the list
                if(teamList.at(j).getGroundRating() > maxGround) {          //If they are better at fielding
                    maxGround = teamList.at(j).getGroundRating();
                    positionOfMax = j;                                      //They are the new highest
                }
            }
            playerLocations.setSecondBase(teamList.at(positionOfMax));      //Set the second baseman as this player
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Add them to the assigned players
            teamList.remove(positionOfMax);                                 //Remove them from the original list
            teamList.assignTail();
        } else if(i == 6) {             //Assign the seventh MOST IMPORTANT player
            int maxFly = teamList.at(0).getFlyRating();     //Left field is second most important
            int positionOfMax = 0;                          
            for(int j = 0; j < teamList.size(); j++) {      //For each player in the list
                if(teamList.at(j).getFlyRating() > maxFly) {        //If the stat is greater than the max
                    maxFly = teamList.at(j).getFlyRating();         //They are the new best outfielder
                    positionOfMax = j;
                }
            }
            playerLocations.setRightField(teamList.at(positionOfMax));      //Set right field as this player
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Insert them into the assigned players
            teamList.remove(positionOfMax);                                 //Remove them from the original list
            teamList.assignTail();                                          //Assign the tail of the list
        } else if(i == 7) {
            int maxGround = teamList.at(0).getGroundRating();       //Find the ground rating of the first player
            int positionOfMax = 0;
            for(int j = 0; j < teamList.size(); j++) {                  //For each player in the list
                if(teamList.at(j).getGroundRating() > maxGround) {      //If the rating is higher
                    maxGround = teamList.at(j).getGroundRating();       //They are better at fielding
                    positionOfMax = j;
                }
            }   
            playerLocations.setFirstBase(teamList.at(positionOfMax));       //Sets the first base as this player
            assignedPlayers.insert(i, teamList.at(positionOfMax));          //Adds them to the assigned players
            teamList.remove(positionOfMax);                                 //removes them from the list
            teamList.assignTail();
        } else if (i == 8) {
            int positionOfMax = 0;                                      //Catcher is the last in the list
            playerLocations.setCatcher(teamList.at(positionOfMax));     //Set the catcher
            assignedPlayers.insert(i, teamList.at(positionOfMax));      //Insert them into the assigned players
            teamList.remove(positionOfMax);                             //Remove them from the original list
            teamList.assignTail();                                      //Assign the tail of the list
        }
    }
}
