/* CSCI 261: Lab 3B Strings Test Suite
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     
 *
 * Create a .cpp file that passes all tests
 */
// The include section adds extra definitions from the C++ standard library.
#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;         //Variable to store length
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';     //Initialize the character of the array
    
    result = STR.at(IDX);   //Set result as the char at the IDX
    return result;          //Return result
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;    //Reuslt is the left side

    result += RIGHT;        //Add the right side
    return result;          //Return result
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;                //make result variable

    string left = STR.substr(0, IDX);   //Split STR into the left and right
    string right = STR.substr(IDX);
    string middle = TO_INSERT.substr(0);   //Make a variable for the inserted string
    result = left;
    result += middle;               //Concatonate all strings
    result += right;
    return result;              //return result

}

int string_find(const string STR, const char C)  {
    int result = -1;        //Sets result as -1
    
    result = STR.find(C);   //Finds the character and returns the index
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;        //Make the resuly the whole string
    
    result = STR.substr(IDX, LEN);  //Change it to the string between IDX and LEN
    return result;      //Return the string
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;            //Result is the str
    
    size_t replaceStart = STR.find(TEXT_TO_REPLACE);    //Find the index of where to replace
    if(replaceStart > STR.length()){           //If the stringToReplace is not in STR
        return result;      //Reuturn the original string
    }
    result = result.replace(replaceStart, TEXT_TO_REPLACE.length(), REPLACE_WITH);  //else result is the replaced string
    return result;      //Return result
}   

string string_first_word(const string STR)  {   
    string result = STR;        //Result is the STR
    
    result = result.substr(0, result.find(" "));    //Result is the first letter until first space

    return result;      //Return result
}

string string_remove_first_word(const string STR)  {    
    string result = STR;        //Result is the STR

    size_t firstSpace = result.find(" ");   //Find the first space
    if(firstSpace > result.length()){      //If result is one word
        result = "";        //Remove the word
        return result;      //return ""
    }
    result = result.erase(0, firstSpace + 1);   //Else, erase the first word
    return result;  //Return the result
}

string string_second_word(const string STR)  {
    string result = STR;
    
     size_t firstSpace = result.find(" ");
    if(firstSpace > result.length()){       //SAME FUNCTION TO REMOVE FIRST WORD
        result = "";
        return result;
    }
    result = result.erase(0, firstSpace + 1);
    result = result.substr(0, result.find(" "));    //After removing the first word, return the second
    return result;
}

string string_third_word(const string STR)  {
    string result = STR;
    
    for(int i = 0; i < 2; i++){                 //SAME FUNCTION TO REMOVE A WORD
         size_t firstSpace = result.find(" ");  //LOOPED TWICE TO REMOVE 2 WORDS
        if(firstSpace > result.length()){
            result = "";
            return result;
    }
    result = result.erase(0, firstSpace + 1);
    }
    result = result.substr(0, result.find(" "));    //Find the new first word
    return result;          //Return result
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    
    for(int i = 1; i < N; i++){                 //SAME FUNCTION TO REMOVE A WORD
        size_t firstSpace = result.find(" ");   //LOOPED N times
        if(firstSpace > result.length()){
            result = "";
            return result;
        }
        result = result.erase(0, firstSpace + 1);
    }
    result = result.substr(0, result.find(" "));    //Find the new first word
    return result;          //Return the word
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    
    for(int i = 0; i < STR.length(); i++){  //Substitutes the target character only
        if(result[i] == TARGET){
            result[i] = REPLACEMENT;
        }
    }
    return result;          //Returns the new list
}

string string_to_lower(const string STR) {      
    string result = STR;
    
    for(int i = 0; i < STR.length(); i++){          //For every character in the STR
        result[i] = putchar(tolower(result[i]));    //Put the character to lowercase
    }
    return result;          //Return result
}

string string_to_upper(const string STR) {  
    string result = STR;
    
    for(int i = 0; i < STR.length(); i++) {     //For every character in STR
        result[i] = putchar(toupper(result[i]));    //Put the character to uppercase
    }
    return result;      //Return the string
}

int string_compare(const string LHS, const string RHS) {
    int result = 1;
                        //Compares left hand side and rhs
    if(LHS > RHS){
        result = 1;
    }
    if(LHS == RHS){
        result = 0;
    }
    if(LHS < RHS){          //Values for -1 and 1 are given in string_functions.h
        result = -1;
    }
    return result;  //return result
}