#include "array_functions.h"



void array_allocate(int* &pArray, const int INIT_SIZE){     //Allocates integer array of INIT_SIZE on the freestore
    pArray = new int[INIT_SIZE];                            //pArray points to the starting adress
    for(int i = 0; i < INIT_SIZE; i++){                     //All values initiated to 0
        pArray[i] = 0;                                      //Runtime is O(n) since all indexes have to be initialized
    }
    
}

int array_get_element_at(int *pArray, const int SIZE, const int POS){   //Returns value of element at POS
    int desiredElement = pArray[POS];       //The value is an offset of POS from the starting adress
    return desiredElement;                  //Runtime is O(1) since all you need is the offset and starting address
}
void array_set_element_at(int *pArray, const int SIZE, const int POS, const int VALUE){ //Sets the value of the position in the array
    if(POS > (SIZE - 1)){   //If POS is not an availible index in the array
        return;             //Do nothing
    }
    pArray[POS] = VALUE;    //Changes the index POS to the VALUE
                            //Runtime is O(1) since the offset and address are only needed
}

void array_deallocate(int* &pArray, int &size){ //Deallocates integer array returning memory to freestore
    delete[] pArray;
    pArray = nullptr;   //Reinitialize as nullptr
    size = 0;           //size is 0
                        //runtime is O(n) since it has to delete every element
}

void array_insert_at_position(int* &pArray, int &size, const int POS, const int VALUE){ //Inserts a value at a target position
    int *newList = new int[size + 1];       //New list that is one space bigger than pArray's
    int position = 0;           //position variable for if POS is out of range
    if(POS < 0) {           //If POS is negative
        position = 0;       //Insert at the beginning
    } else if(POS > size) {    //If POS is larger than size
        position = size;        //position equals size, (valid arguement in newList)
    } else {                
        position = POS;     //Else position is just POS
    }
    for(int i = 0; i < size + 1; i++){  //For each element in the original list
        if(i < position){               //If index is before the inserted element
            newList[i] = pArray[i];     //Copy it to newList
        } else if(i == position){       //If index is the inserted element, 
            newList[i] = VALUE;         //Insert Value
        } else {                        //If index is after than inserted element
            newList[i] = pArray[i - 1];     //Insert the value 1 back in pArray since we added an element
        }
    }
    delete[] pArray;    //Delete the original list
    pArray = newList;   //Set pArray as the newList
    size += 1;          //Update the size
                        //RUNTIME is O(n) since every element must be copied
}

int array_min(int *pArray, const int SIZE){    //Finds the min value in the array
    int currentMinimum = 0;                 //Initialize a variable for the min
    if(SIZE == 0 || pArray == nullptr) {    //If the size is 0 or pArray is nullptr
        return 0;       //Return 0
    } else {
        currentMinimum = *pArray;       //Else, minimum is the first element in pArray
    }
    for(int i = 0; i < SIZE; i++) {     //For each element in pArray
        if(pArray[i] < currentMinimum) {    //If the element is less than the currentMinimum
            currentMinimum = pArray[i];     //update the minimum
        }
    }
    return currentMinimum;          //Return the minimum
}                                   //RUNTIME is O(n) since every element must be checked

int array_max(int *pArray, const int SIZE){     //Finds the max value in the array
    int currentMaximum = 0;         //Set variable for the maximum
    if(SIZE == 0 || pArray == nullptr) {    //If the size is 0 or pArray is nullptr
        return 0;       //Return 0
    } else {            
        currentMaximum = *pArray;   //Else, the currentMax is the first element
    }
    for(int i = 0; i < SIZE; i++) {     //For every element in pArray
        if(pArray[i] > currentMaximum) {        //If the element is > maximum
            currentMaximum = pArray[i];     //Update currentMaximum
        }
    }
    return currentMaximum;          //Return the maximum
}                                   //RUNTIME is O(n) since every element is checked

int array_find(int *pArray, const int SIZE, const int TARGET){  //Finds and returns the index of the desired element
    for(int i = 0; i < SIZE; i++) {     //For each element in the array
        if(pArray[i] == TARGET){        //If the element is the TARGET
            return i;                   //Return the index
            break;
        }               //If not found
    }
    return -1;          //Return -1
}                       //RUNTIME is O(n), worst case every element is checked

void array_remove_from_position(int* &pArray, int &size, const int POS){ //Removes array element at certain position
    if(size == 0){
        return;
    }
    int* shortenedList = new int[size - 1];         //Shortened list is one space smaller
    int position = POS;         //position variable for if POS is out of range, equal to POS
    if(position < 0){           //If position is less than 0, 
        position = 0;           //position is the first index
    } else if(position >= size){        //If position is >= size, which is out of pArray's size
        position = (size - 1);          //position is the last index in pArray
    }
    for(int i = 0; i < (size - 1); i++) {   //For each element in the shortenedList
        if(i < position) {                  //If i is before the excluded element
            shortenedList[i] = pArray[i];   //Copy the element
        } else if(i >= position) {          //Else if i is at the position or farther
            shortenedList[i] = pArray[i + 1];       //Skip the element and copy the later ones
        }
    }
    delete[] pArray;            //Delete the array
    pArray = shortenedList;     //pArray is the shortenedList
    size -= 1;                  //Size is 1 smaller
}