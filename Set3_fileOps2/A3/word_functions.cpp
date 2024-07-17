/* CSCI 261: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Patrick Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * Create .cpp and headerfile for main to count occurances of letters and unique words.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <fstream>
#include <vector>

using namespace std;


string prompt_user_for_filename(){      //Ask user for the input text file
    string file = "";                   //Initialize file variable
    cout << "Enter the name of the file to be operated on. " << endl;  
    cin >> file;        //User enters the name of the file
    return file;        //return file name
}

bool open_file(ifstream& fileIn, const string &nameOfFile){     //Open the file passed with the ifstream object
    fileIn.open(nameOfFile);       //Attempts to open the file
    if(fileIn.fail()){              //Check for opening error
        cout << "The file failed to open." << endl; //If error notify user of file opening error 
        return false;                               //Return false
    } else {
        return true;        //If it succeeds, return true
    }
}

vector<string> read_words_from_file(ifstream& fileIn){    //Read the words from the ifstream object into a vector
    vector<string> fileContents;            //Create new vector of strings
    string currentWord;                     //Declare a string variable
    while(fileIn >> currentWord){                   //While next word is put into string variable
        fileContents.push_back(currentWord);    //Add the string the vector
    }
    return fileContents;        //Return the vector
}

void remove_punctuation(vector<string>& allWords, const string punctuation){   //Removes punctuation
    for(unsigned int i = 0; i < allWords.size(); i++){      //for each element in allWords vector
        string currentWord = allWords[i];           //New string is the current word
        for(int j = 0; j < currentWord.length(); j++){      //For each character in the curent word
            if(punctuation.find(currentWord[j]) != string::npos){   //If the character is found,
                currentWord.erase(j, 1);                            //erase the character
                j -= 1;                                  //Decrease j for the length
            }
        }
        allWords[i] = currentWord;      //Set allWords at i'th index to the currrent Word
    } 
}

void capitalize_words(vector<string>& allWords){    //Capitalizes all characters
    for(unsigned int i = 0; i < allWords.size(); i++){  //For each word in the list
        string currentWord = allWords[i];               //new string is the current word
        for(unsigned int j = 0; j < currentWord.length(); j++){     //For each letter in the current word
            currentWord[j] = toupper(currentWord[j]);       //Change it to uppercase
        }
        allWords[i] = currentWord;          //Set the vector element as the uppercase version
    }
}

vector<string> filter_unique_words(vector<string>& allWords){   //Takes out duplicate words
    vector <string> uniqueWords;            //New vector for unique words
    for(unsigned int i = 0; i < allWords.size(); i++){  //For each word in allWords
        string currentWord = allWords[i];       //currentWord is equal to current element
        bool isWordContained = false;           //Set the defult to "not contained"
        for(unsigned int j = 0; j < uniqueWords.size(); j++){   //For each element in the new list, 
            if(currentWord == uniqueWords[j]){                  //If the word is already inside
                isWordContained = true;         //Set isWordContained to true
            }
        }
        if(!isWordContained) {              //If word is not contained
            uniqueWords.push_back(currentWord);     //Add word to unique words
        }
    }
    return uniqueWords;     //Return unique words
}

void count_letters(unsigned int (&letters)[26], const vector<string>& allWords){    //Counts all letters
    for(unsigned int i = 0; i < allWords.size(); i++) {     //For each word in allWords
        string currentWord = allWords[i];             //New string for the current index in allWords
        for(unsigned int j = 0; j < currentWord.length(); j++) {    //For each character in the string
            char currentCharacter = currentWord[j];             //Store the character in a variable
            //use ascii ordering shifted back 65 to map characters to indexes
            letters[(int)currentCharacter - 65] = letters[(int)currentCharacter - 65] + 1; 
        }
    }
}

void print_letter_counts(unsigned int (&letters)[26]){      //Prints the frequency of each letter
    int currentMax = letters[0];
    int maxLength = 0;
    for(int k = 0; k < 26; k++){
        if(letters[k] > currentMax){
            currentMax = letters[k];
        }
    }
    maxLength = to_string(currentMax).length();
    for(int i = 0; i < 26; i++){        //For each index in the array
        cout << char(i + 65) << ": " << setw(maxLength) << letters[i] << endl; //Cout the character +65 for ascii, and the frequency

    }
}

void print_max_min_letter(const unsigned int (&letters)[26]) {  //print the max and minimum letters
    unsigned int minimum = letters[0];  //New variables to initialize the max and min
    int indexOfMinimum = 0;             //Also to store which index is the max and min
    unsigned int maximum = letters[0];
    int indexOfMaximum = 0;
    double maxFrequency = 0;
    double minFrequency = 0;
    int totalCharacters = 0;
    int maxLength = 0;
        for(int i = 0; i < 26; i++){        //for each character in the alphabet
            totalCharacters += letters[i];
            if(letters[i] > maximum) {  //If the frequency is more than currentMax, 
                maximum = letters[i];   //Set it to the newMax
                indexOfMaximum = i;
            }
            if(letters[i] < minimum) {  //If the frequency is less than the minimum,
                minimum = letters[i];    //Update minimum and indexes
                indexOfMinimum = i;
            }
        }
    maxLength = to_string(letters[indexOfMaximum]).length();
    maxFrequency = (letters[indexOfMaximum] / (double)totalCharacters) * 100;
    minFrequency = (letters[indexOfMinimum] / (double)totalCharacters) * 100;
    cout << fixed;
    if(maxFrequency >= 10){
    cout << "Least Frequent Letter: " << (char)(indexOfMinimum + 65) << " " << setw(maxLength) << minimum << " (  " << setprecision(3) << minFrequency << "%)" << endl;     //Use the index to print the character in ascii and its frequency
    cout << " Most Frequent Letter: " << (char)(indexOfMaximum + 65) << " " << setw(maxLength) << maximum << " ( " << setprecision(3) << maxFrequency << "%)" << endl;
    }
    if(maxFrequency < 10){
        cout << "Least Frequent Letter: " << (char)(indexOfMinimum + 65) << " " << setw(maxLength) << minimum << " ( " << setprecision(3) << minFrequency << "%)" << endl;     //Use the index to print the character in ascii and its frequency
        cout << " Most Frequent Letter: " << (char)(indexOfMaximum + 65) << " " << setw(maxLength) << maximum << " ( " << setprecision(3) << maxFrequency << "%)" << endl;
    }
}