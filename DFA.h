#pragma once
#ifndef _DFA
#define _DFA

#include <string>

enum State {
	START, FOUND_A, FOUND_L,FOUND_E,FOUND_X,FOUND_A2,FOUND_SPACE,FOUND_D, FOUND_E2, FOUND_V, FOUND_O, FOUND_R, FOUND_A3, FOUND_ALEXADEVORA, ACCEPT
};

State transition(State current, char input);

bool searchString(const std::string& input);















#endif