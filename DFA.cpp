#include "DFA.h"

// Constructor
DFA::DFA(const std::string& first, const std::string& last)
    : firstName(first), lastName(last) {
    reset();
}

// Reset 
void DFA::reset() {
    phase = MATCH_FIRST;
    idx1 = 0;
    idx2 = 0;
}

void DFA::processChar(char c) {
    if (phase == MATCH_FIRST) {

        if (c == firstName[idx1]) {
            idx1++; 
            if (idx1 == firstName.size()) {
                phase = MATCH_LAST;
                idx2 = 0; 
            }
        }
        else if (c == firstName[0]) {
            idx1 = 1;
        }
    }
    else if (phase == MATCH_LAST) {
        if (c == lastName[idx2]) {
            idx2++; 
            if (idx2 == lastName.size()) {
                phase = ACCEPT;
            }
        }
        else if (c == lastName[0]) {
            idx2 = 1;
        }
    }
}

bool DFA::isAccepted() const {
    return phase == ACCEPT;
}

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
