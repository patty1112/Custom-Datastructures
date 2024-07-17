#include "array.hpp"
using namespace std;

int main() {
    Array<int> newArray;
    cout << "Testing insert and remove." << endl;
    cout << "Printing the array after default construction." << endl;
    newArray.print();  
    cout << "Add the value 6 at the end." << endl;
    newArray.insert(5, 6);  
    newArray.print();
    cout << "Add the value 0 at the 1st index" << endl;
    newArray.insert(1, 0);
    newArray.print();
    cout << "Add the value -5 at the 1st index" << endl;
    newArray.insert(1, -5);
    newArray.print();
    cout << "Add the value -100 at the 3rd index" << endl;
    newArray.insert(3, -100);
    newArray.print();
    cout << "Remove the 2nd index." << endl;
    newArray.remove(2);
    newArray.print();
    cout << "Remove out of range, does nothing." << endl;
    newArray.remove(100);
    newArray.print();
    cout << "Remove out of range." << endl;
    newArray.remove(5);
    newArray.print();
    cout << "Remove out of range." << endl;
    newArray.remove(4);
    newArray.print();
    cout << "Remove out of range." << endl;
    newArray.remove(-1);
    newArray.print();
    cout << "Remove the last index, (size - 1)." << endl;
    newArray.remove(newArray.listSize() - 1);
    newArray.print();

    cout << "Testing the assignment and copy operators." << endl;
    Array<int> copyArray(newArray);
    Array<int> assignedArray;
    assignedArray = newArray;
    cout << "Printing the three, they should be the same." << endl;
    newArray.print();
    copyArray.print();
    assignedArray.print();
    newArray.remove(0);
    copyArray.remove(1);
    assignedArray.remove(2);
    newArray.print();
    copyArray.print();
    assignedArray.print();
    cout << "hi" << endl;
    for(int i = 0; i < copyArray.listSize(); i++) {
        cout << *copyArray.get(i) << " ";
    }
    cout << endl;   

}