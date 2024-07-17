/* CSCI 261: Lab 5C Towers of Hanoi
 *
 * Author: Patrick Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#include <iostream>
using namespace std;

/**
 * @brief Recursive solution to move N disks from a starting peg to a target peg
 *
 * @param N the number of disks to move
 * @param START_PEG ID of the peg the disks are currently on
 * @param TARGET_PEG ID of the peg the disks need to move to
 * @param SPARE_PEG ID of the peg that can be used as temporary storage
 *
 * @note Outputs the series of moves to standard otu to solve the problem for N disks
 */
void towers_of_hanoi(const int N, const int START_PEG, const int TARGET_PEG, const int SPARE_PEG) {
    
    if(N == 1) {      //If there is only one disk to move...                  
                    //Move the disk.                          
        cout << "Move disk " << N << " from " << START_PEG << " to " << TARGET_PEG << endl;     
        // base case - if there are no more disks to move, then we are done!  do nothing
    } else {
        // recursive case
        // Step 1: recursively move the top N-1 disks from our current peg
        // to the non-target peg
        towers_of_hanoi(N - 1, START_PEG, SPARE_PEG, TARGET_PEG);
        // Step 2: move the largest disk that was on the bottom from our
        // current peg to the target peg
        // (perform the move by printing what disk moves from where to where)
        cout << "Move disk " << N << " from " << START_PEG << " to " << TARGET_PEG << endl;
        // Step 3: recursively move the remaining N-1 disks from the non-target
        // peg to our target peg on top of the largest disk we just moved
        towers_of_hanoi(N - 1, SPARE_PEG, TARGET_PEG, START_PEG);
    }
}

int main() {
    const int STARTING_PEG = 0;         // 0 - ID of the peg our disks start on
    const int TARGET_PEG = 2;           // 2 - ID of the peg we need to move our disks to
    const int SPARE_PEG = 1;            // 1 - ID of the peg that can be used for temp storage

    int numberOfDisks;
    cout << "Enter number of disks to solve: ";
    cin >> numberOfDisks;               // user enters the number of disks to solve for

    // solve Towers of Hanoi problem for numberOfDisks disks
    // disks are initially on our starting peg and need to move to our target peg
    towers_of_hanoi( numberOfDisks, STARTING_PEG, TARGET_PEG, SPARE_PEG );

    return 0;
}