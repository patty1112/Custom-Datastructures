#include "Stack.hpp"
#include "Queue.hpp"

#include <iostream>
using namespace std;

int main() {
    Stack<int> stacker;
    stacker.push(1);
    stacker.push(2);
    stacker.push(3);
    stacker.push(4);
    stacker.push(5);
    while( !stacker.isEmpty() ) {
        cout << "stack top is: " << stacker.peak() << " \t";
        int top = stacker.pop();
        cout << "stack top was: " << top << endl;
    }
    cout << "stack is empty" << endl;

    cout << endl;

    Queue<int> queuer;
    queuer.push(1);
    queuer.push(2);
    queuer.push(3);
    queuer.push(4);
    queuer.push(5);
    while( !queuer.isEmpty() ) {
        cout << "queue front is: " << queuer.peak() << "\t";
        int front = queuer.pop();
        cout << "queue front was: " << front << endl;
    }
    cout << "queue is empty" << endl;

    return 0;
}