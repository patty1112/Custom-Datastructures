/* CSCI 261: Assignment 2: A2 PPM Image Editor
 *
 * Author: Patrick Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 * 
 *    //Attended Armando Ocampo's office hours for help on the get_user_input function and how to check type.
 * 
 * Create a program to grayscale images and invert them
 */
// The include section adds extra definitions from the C++ standard library.
#include <string>
#include "ppm_functions.h"
#include <iostream>
#include <fstream>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;



int main() {
    int picture = 0;
    int option = 0;
    string width = " ";
    string height = " ";      //Initialize variables to store file information
    string maxValue = " ";
    string readFile;
    string outputFile = "output.ppm";

    print_file_options();         //Print the options for the picture
    picture = get_user_input(1, 3); //Get the desired picture and store the integer
    print_operation_options();    //Print options for operations
    option = get_user_input(1, 2);  //Get the desired operation and store it
    
    //Open the files, readFile is passed by refrence.
    if(!open_files(readFile, outputFile, picture, option)){ //If there is an error opening
      return 1;     //End the program
    }
    ifstream fileContents(readFile);    //Create input file stream object
    

  if(!read_header_information(fileContents, width, height, maxValue)) { //If the picture is the wrong type
    return 1;       //End the program
  }
  string fileName = "";
    if(picture == 1 && option == 1) {       //Create appropriate names for different choices.
      fileName = "brick_grayscale.ppm";
    } else if(picture == 1 && option == 2) {
      fileName = "brick_inverted.ppm";
    } else if(picture == 2 && option == 1) {
      fileName = "wallpaper_grayscale.ppm";
    } else if(picture == 2 && option == 2) {
      fileName = "wallpaper_inverted.ppm";
    } else { 
      fileName = "output_picture.ppm";
    }
  ofstream fileOutput(fileName);  //Create output file stream object.
    if(fileOutput.fail()) { 
      cerr << "Error opening output file.";    //If it fails, notify and end program
      return 1;
      } else {
      cout << "Writing " << fileName << endl;   }   //notify of new file being written
    write_header_information(fileOutput, width, height, maxValue);    //Write the new file's header
    read_and_write_modified_pixels(fileContents, fileOutput, option, width, height, maxValue);  //Depending on the option, modify pixels.
  return 0; 
}