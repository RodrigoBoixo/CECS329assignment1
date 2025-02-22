#pragma once
#ifndef DFA_H
#define DFA_H

#include <string>

// The matching phase of the DFA.
enum Phase {
    MATCH_FIRST,  // Currently matching the first name
    MATCH_LAST,   // First name matched; now matching the last name
    ACCEPT        // Both names matched; accepting state
};

// DFA class: encapsulates the state for matching a given first and last name.
class DFA {
private:
    std::string firstName; // Target first name (must be all lower-case and contiguous)
    std::string lastName;  // Target last name (must be all lower-case and contiguous)
    Phase phase;           // Current phase (which name are we matching?)
    int idx1;              // Index in the firstName currently matched
    int idx2;              // Index in the lastName currently matched

public:
    // Constructor: initialize the DFA with the target first and last names.
    DFA(const std::string& first, const std::string& last);

    // Reset the DFA to the initial state.
    void reset();

    // Process one character and update the DFA state.
    void processChar(char c);

    // Returns true if the DFA has reached the ACCEPT state.
    bool isAccepted() const;
};

// Helper function that processes the entire input string using the DFA.
// Returns true if the string contains the target first name followed by the target last name.
bool searchString(const std::string& input, const std::string& first, const std::string& last);

#endif // DFA_H
