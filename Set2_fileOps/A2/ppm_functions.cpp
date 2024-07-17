#include <iostream>
#include <fstream>
#include "ppm_functions.h"
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void print_file_options() {
cout << "Welcome to the PPM Image Program!" << endl; //Write file options to the console
cout << "Which image to load?" << endl;
cout << "1. Brick" << endl;
cout << "2. Wallpaper" << endl;
cout << "3. Private" << endl;

}

void print_operation_options() {        //Write file operations to the console
    cout << "Which process to apply?" << endl;
    cout << "1. Convert to grayscale" << endl;
    cout << "2. Invert the colors" << endl;
}

int get_user_input(int minimumInteger, int maximumInteger) {    //Function to prompt user for integer within range
    string userInput = "";
    bool reprompt = 1;
    cout << "Enter an integer between " << minimumInteger << " and " << maximumInteger << endl;
    while(reprompt){
    cin >> userInput;
        if(userInput.length() == 1){
            if(isdigit(userInput[0])){
                if(stoi(userInput) >= minimumInteger && stoi(userInput) <= maximumInteger){
                    
                    reprompt = 0;
                    } else {
                    cout << "The digit must between "  << minimumInteger << " and " << maximumInteger << endl;
                }} else {
                cout << "Enter an integer between the limits. (" << minimumInteger << "," << maximumInteger << ")" << endl;
            }} else {
        cout << "Enter an integer between the limits. (" << minimumInteger << "," << maximumInteger << ")" << endl;
    }}
    return stoi(userInput);
}

bool open_files(string &readFile, string fileToWrite, int picture, int option) {
    switch(picture) {   //Make switch based on picture choice
        case 1: {
          readFile = "brick.ppm";       //If picture == 1, then the read file is brick.ppm
            cout << "Opening brick.ppm file" << endl;
            ifstream fileContents("brick.ppm"); //Open the file, check for errors
            if(fileContents.fail()) {
                cout << "The file failed to open, or was not found." << endl;
                return false;
        }
          break;
         } case 2: {        //If picture == 2, then use wallpaper.ppm
           readFile = "wallpaper.ppm";
            cout << "Opening wallpaper.ppm file" << endl;
            ifstream fileContents("wallpaper.ppm"); //Open the file and check for errors.
            if(fileContents.fail()) {
                cout << "The file failed to open, or was not found." << endl;
                return false;
         }
        break;
         } case 3: {        //If picture == 3, open the private.ppm image.
           readFile = "private.ppm";
            cout << "Opening private.ppm file" << endl;
            ifstream fileContents("private.ppm");    //Open the file and check for error.
            if(fileContents.fail()) {               //Should enter if statement since private doesn't exist.
                cout << "The file failed to open, or was not found." << endl;
                return false;
        }
        break;
      } default:{       //If picture was not a choice, output error
          cout << "There was an error (default) " << endl;
      }
      }
    return true;
}

bool read_header_information(ifstream& fileContents, string &width, string &height, string &maxValue) {
    string pictureType = "";    //Function to read the details of the ppm
    getline(fileContents, pictureType); //Store the first line in pictureType variable.
    if(pictureType != "P3"){            //If the picture is not a P3
        cout << "The picture is not a P3" << endl;  //Notify user and end program
        return false;
    }
    getline(fileContents, width, ' ');  //Get the next line and store in width, separate at the space, (' ')
    getline(fileContents, height);      //Continue from the space and get the height value
    getline(fileContents, maxValue);    //Get the next line and store the maxValue of the pixels
    return true;
}

void write_header_information(ofstream& fileOutput, string &width, string &height, string &maxValue){
    
    fileOutput << "P3" << endl;     //Use the same variables to write identical header to outputPicture.
    fileOutput << width << " ";
    fileOutput << height << endl;
    fileOutput << maxValue << endl;

}

void read_and_write_modified_pixels(ifstream& fileContents, ofstream& fileOutput, int &option, string &width, string &height, string &maxValue) {
    if(option == 1){      //If user wants grayscale...
    try { 
        string original = "";
        string newPixel = "";   //Initialize new strings to store gray values.
        string grayRed = "";
        string grayGreen = "";
        string grayBlue = "";
        cout << "Converting Image to grayscale!" << endl;
        while(!fileContents.eof()) {    //At the end of the file, there will be an error due to math with an EOF string
            newPixel = "";
            original = "";
            grayRed = "";
            grayGreen = "";
            grayBlue = "";
            getline(fileContents, original);   //Get the value of a red pixel
            grayRed += to_string(int((round(0.2989 * stoi(original)))));    //Average the red to gray and store in grayRed
            original = "";                      //Empty the original variable      
            getline(fileContents, original);    //Get the value of a green pixel
            grayGreen += to_string(int((round(0.5870 * stoi(original)))));  //Average the green to gray and store in grayGreen
            original = "";                      //Empty variable
            getline(fileContents, original);  //Get the value of a blue pixel
            grayBlue += to_string(int((round(0.1140 * stoi(original)))));   //Average the blue to gray and store in grayBlue
            newPixel += to_string(stoi(grayRed) + stoi(grayGreen) + stoi(grayBlue)); //Calculate the combined gray and store the newpixel
            fileOutput << newPixel << endl;
            fileOutput << newPixel << endl; //Write the pixel 3 times to the same file to make an RGB triple
            fileOutput << newPixel << endl;
        }
        
        } catch(...) {                      //Catch the EOF error or any other errors, close the file
            cout << "The file has ended and is closed" << endl;
            fileContents.close();
            fileOutput.close();
        }
    }
    if(option == 2) {                       //If user wants to invert the colors...
        try {
            string original = "";           //Initialize string variables
            string invertedRed = "";
            string invertedGreen = "";
            string invertedBlue = "";
            cout << "Inverting the picture's colors!" << endl;
            while(!fileContents.eof()) {                //While the file hasn't ended...
                original = "";
                invertedRed = "";                       //Clear variables for while loop
                invertedGreen = "";
                invertedBlue = "";
                getline(fileContents, original);        //Store the red in the original variable
                invertedRed += to_string(int((stoi(maxValue) - stoi(original))));   //Subtract it from the maxValue
                fileOutput << invertedRed << endl;      //Write the inverted red to the file
                original = "";                          //Clear original
                getline(fileContents, original);        //Store the green in original
                invertedGreen += to_string(int((stoi(maxValue) - stoi(original)))); //Subtract it from maxValue
                fileOutput << invertedGreen << endl;    //Write the inverted green to the file
                original = "";                          //Clear original
                getline(fileContents, original);        //Store the blue in original
                invertedBlue += to_string(int((stoi(maxValue) - stoi(original))));  //Subtract it from max value 
                fileOutput << invertedBlue << endl;     //Write the inverted blue to the file
        }
        } catch(...) {                                  //Catch error from math with EOF string
            cout << "The file has ended and is closed" << endl;
            fileContents.close();       //Output error and close files.
            fileOutput.close();
        }
} }
