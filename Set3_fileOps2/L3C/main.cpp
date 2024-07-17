/* CSCI 261: Lab 3C Pointers
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     
 *
 * Grow familiar with pointers by implementing the psudocode in L3C
 */
// The include section adds extra definitions from the C++ standard library.

#include <iostream>
using namespace std;

int main() {
    //Declare an integer named iNum with initial value 9.
    int iNum = 9;
    //Declare a double named dNum with initial value 14.25.
    double dNum = 14.25;
    //Declare two pointers to integers named pINum1 and pINum2.
    int *pINum1;
    int *pINum2;
    //Declare a pointer to a double named pDNum.
    double *pDNum;
    //Assign the address of iNum to pINum1.
    pINum1 = &iNum;
    //Output the address of iNum and be sure to identify to the user what you are displaying. 
    //There are two ways you can do this; you should do both, to convince yourself they are the same.
    cout << &iNum << " <- This is the adress of iNum, (&iNum)." << endl << endl;
    cout << pINum1 << " <- This is the pointer to iNum's adress, (pINum1)." << endl << endl;
    //Use pINum1 to display the contents of iNum.
    cout << *pINum1 << " <- This is the value of iNum using *pINum1." << endl << endl;
    //Try to assign the address of dNum to pINum2. Compile your program. What error message do you see? Comment out this bad line of code, but include the error message as a comment with this line.
    // pINum2 = &dNum;
    //Error: incompatible pointer types assigning to 'int *' from 'double *'

    //Assign the address of dNum to pDNum.
    pDNum = &dNum;
    //Output the address and then the contents of dNum (using pDNum).
    cout << pDNum << " <- This is the adress of dNum using the pDNum pointer." << endl << endl;
    cout << *pDNum << " <- This is the value of dNum using the pDNum pointer." << endl << endl;
    //Directly change the value of iNum to 7.
    iNum = 7;
    //Use pINum1 to output the contents of iNum.
    cout << *pINum1 << " <- This is the value of iNum using pINum1. " << endl << endl;
    //Assign pINum2 to have the same value as pINum1. Do not reference iNum; instead use the address stored in pINum1.
    pINum2 = pINum1;
    //Output the address in pINum2.  This should be the same as displayed in step 6.
    cout << pINum2 << " <- This is the adress stored in PINum2." << endl << endl;
    //Output the value pointed to by pINum2.
    cout << *pINum2 << " <- This is the value stored by the pointer pINum2." << endl << endl;
    //Using pINum2, change the contents of iNum to 12.
    *pINum2 = 12;
    //Output the contents of iNum three times, first using pINum1, then using pINum2, then iNum directly. 
    //In each case, identify what the user is seeing appropriately.
    cout << *pINum1 << " <- This is the value of pINum1." << endl;
    cout << *pINum2 << " <- This is the value of pINum2." << endl;
    cout << iNum << " <- This is the actual value of iNum" << endl;


    return 0;
}
