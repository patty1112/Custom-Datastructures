#include <fstream>
#include <iostream>
using namespace std;

int main() {

ofstream fileOutput("decipheredMessage.txt");   //Create output file stream object
if(fileOutput.fail()) {
    cerr << "Error opening output file.";       //Check for error
    return 1;                                   //If error, exit program
}
    // declare ofstream object and open the file
ifstream fileContents("secretMessage.txt");
    // check for an error
if ( fileContents.fail() ) {
    cerr << "Error opening input file";
    return 1;
    }

string original;
while(!fileContents.eof()) {        //For every line in the input file
getline(fileContents, original);                
    for(int i = 0; i < original.size(); i++) {     //for every character in the line
        if(original[i] == '~') {                //If its a ~ then change it to a ' '
            original[i] -= 94;     
            
            } else if (original[i] == '\n') {   //If its an new line, leave it
                continue;
            } else {
                original[i] += 1;               //Other characters incriment by 1
            }
    }
    fileOutput << original;                 //Write the line to the new file
}
    // close the file
    fileContents.close();
    fileOutput.close();         //close the file

    return 0;
}