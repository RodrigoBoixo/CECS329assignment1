// Resources used:
// https://www.geeksforgeeks.org/dfa-accepting-all-strings-over-w-%E2%88%88ab-which-contains-aba-as-a-substring/
// https://www.usna.edu/Users/cs/wcbrown/courses/F18SI340/lec/l05/lec.html
#include <iostream>
#include <string>

using namespace std;

int stateCheck(int currentState, char currentChar); // Transition function

int main()
{
    string input = "";
    int currentState = 0;

    cout << "Enter a string: ";
    getline(cin, input); // Read input

    for (int i = 0; i < input.size(); i++) // Process each character
    {
        currentState = stateCheck(currentState, input[i]);
    }

    // Check if the final state is accepting
    if (currentState == 7) // 7 is the accepting state 
    {
        cout << "accept" << endl;
    }
    else
    {
        cout << "reject" << endl;
    }
}

int stateCheck(int currentState, char currentChar)
{
    // Definition of the substrings to match
    string danh = "danh";
    string ngo = "ngo";

    // Transition logic
    switch (currentState)
    {
        // Matching "danh"
        case 0:
            if (currentChar == danh[0]) // 'd'
            {
                return 1;
            }
            else
            {
                return 0; // Stay in state 0
            }
        case 1:
            if (currentChar == danh[1]) // 'a'
            {
                return 2;
            }
            else
            {
                return 1; // Stay in state 1
            }
        case 2:
            if (currentChar == danh[2]) // 'n'
            {
                return 3;
            }
            else
            {
                return 2; // Stay in state 2
            }
        case 3:
            if (currentChar == danh[3]) // 'h'
            {    
                return 4; // "danh" matched
            }
            else
            {
                return 3; // Stay in state 3
            }

        // Matching "ngo" after "danh"
        case 4:
            if (currentChar == ngo[0]) // 'n'
            {    
                return 5;
            }
            else
            {
                return 4; // Stay in state 4
            }
        case 5:
            if (currentChar == ngo[1]) // 'g'
            {
                return 6; // Stay in state 6
            }
            else
            {
                return 5; // Stay in state 5
            }
        case 6:
            if (currentChar == ngo[2]) // 'o'
            {
                return 7; // Accepting state
            }
            else
            {
                return 6; // Stay in state 6
            }

        // Accepting state
        case 7:
        {
            return 7; // Stay in accepting state
        }

        default:
        {
            return currentState; // Invalid state 
        }
    }
}