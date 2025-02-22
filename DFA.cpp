#include "DFA.h"

// Constructor: stores the target names and resets the state.
DFA::DFA(const std::string& first, const std::string& last)
    : firstName(first), lastName(last) {
    reset();
}

// Reset the DFA to start matching from scratch.
void DFA::reset() {
    phase = MATCH_FIRST;
    idx1 = 0;
    idx2 = 0;
}

// processChar: updates the DFA's state based on the input character.
// Arbitrary characters are allowed; the DFA only advances when a match is found.
void DFA::processChar(char c) {
    if (phase == MATCH_FIRST) {
        // If the current character matches the expected character in the first name.
        if (c == firstName[idx1]) {
            idx1++; // Advance in firstName
            // If the entire firstName is matched, switch to matching lastName.
            if (idx1 == firstName.size()) {
                phase = MATCH_LAST;
                idx2 = 0; // Reset last name index
            }
        }
        // If the character matches the first letter of firstName, restart the matching.
        else if (c == firstName[0]) {
            idx1 = 1;
        }
        // Otherwise, do nothing—since arbitrary characters are allowed.
    }
    else if (phase == MATCH_LAST) {
        // Now matching the last name.
        if (c == lastName[idx2]) {
            idx2++; // Advance in lastName
            // If the entire lastName is matched, move to ACCEPT state.
            if (idx2 == lastName.size()) {
                phase = ACCEPT;
            }
        }
        // If the character matches the first letter of lastName, restart last name matching.
        else if (c == lastName[0]) {
            idx2 = 1;
        }
        // Otherwise, ignore the character.
    }
}

// isAccepted: returns true if both names have been matched.
bool DFA::isAccepted() const {
    return phase == ACCEPT;
}

// searchString: uses the DFA to process an entire input string.
// Returns true if the target pattern (first name followed by last name) is found.
bool searchString(const std::string& input, const std::string& first, const std::string& last) {
    DFA dfa(first, last);
    for (char c : input) {
        dfa.processChar(c);
        if (dfa.isAccepted()) {
            return true;
        }
    }
    return dfa.isAccepted();
}
