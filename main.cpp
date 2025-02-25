#include <iostream>
#include <string>

using namespace std;


int stateTransition(int currentState, char inputChar);

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  

   
    if (input.empty()) {
        cout << "reject" << endl;
        return 0;
    }

    int currentState = 0; 

    for (char c : input) {
        currentState = stateTransition(currentState, c);
    }

    if (currentState == 11) {
        cout << "accept" << endl;
    } else {
        cout << "reject" << endl;
    }

    return 0;
}

int stateTransition(int currentState, char inputChar)
{
    const string target = "alexadevora";

    if (inputChar == target[currentState]) {
        return currentState + 1;  
    }

    return currentState;
}

