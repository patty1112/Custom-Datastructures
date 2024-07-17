#include <iostream>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "fileFunctions.hpp"

using namespace std;

int main(int argc, char* argv[]) {      //Main takes 2 arguements 
    string fileName = "";               //File name is empty
    if(argc == 1) {                     //If there was only one arguement
        fileName = promptUserForFileName();     //Prompt the file name
    } else if (argc == 2) {         //If the user entered the file name
        fileName = argv[1];         //The file name is the second arguement
    } else {            //Else tell the user how to enter a file
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "filename is an optional parameter, can be entered later." << endl;
    }
    
    ifstream fileContents;      //Make input file stream
    if(!open_file(fileContents, fileName)) {        //Open the file and test if it fails
        cerr << "Could not open file, shutting down..." << endl;    //If fail end the program
        return -1;
    }
    cout << "File successfully opened!" << endl << endl;

    int dimensions = 0;
    fileContents >> dimensions;
    
    DoublyLinkedList<DoublyLinkedList<int> > parentList;
    for(int j = 0; j < dimensions; j++) {
        DoublyLinkedList<int> listToInsert;
        for(int i = 0; i < dimensions; i++) {
            int currentValue = 0;
            fileContents >> currentValue;
            listToInsert.insert(dimensions, currentValue);
        }
        parentList.insert(dimensions, listToInsert);
    }

    

    cout << "The table is: " << endl;
    for(int i = 0; i < dimensions; i++) {
        for(int j = 0; j < dimensions; j++) {
            cout << parentList.get(i).get(j) << " ";
        }
        cout << endl;
    }

    int minimum = parentList.get(0).getMin(); 
    int maximum = parentList.get(0).getMax();
    for(int i = 0; i < dimensions; i++) {
         int newMinimum = parentList.get(i).getMin();
         int newMaximum = parentList.get(i).getMax();
         if(newMaximum > maximum) {
             maximum = newMaximum;
         }
         if(newMinimum < minimum) {
             minimum = newMinimum;
         }
    }
    cout << "The min is: " << minimum << endl;
    cout << "The max is: " << maximum << endl;

    fileContents.close();
    return 0;
}