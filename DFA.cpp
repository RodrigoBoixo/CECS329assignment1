#include "DFA.h"

State transition(State current, char input) {
	switch (current) {
		case START:
			if (input == 'a') return FOUND_A;
			break;
		case FOUND_A:
			if (input == 'l') return FOUND_L;
			break;
		case FOUND_L:
			if (input == 'e') return FOUND_E;
			break;
		case FOUND_E:
			if (input == 'x') return FOUND_X;
			break;
		case FOUND_X:
			if (input == 'a') return FOUND_A2;
			break;
		case FOUND_A2:
			if (input == 'd') return FOUND_D;
			break;
		case FOUND_D:
			if (input == 'e') return FOUND_E2;
			break;
		case FOUND_E2:
			if (input == 'v') return FOUND_V;
			break;
		case FOUND_V:
			if (input == 'o') return FOUND_O;
			break;
		case FOUND_O:
			if (input == 'r') return FOUND_R;
			break;
		case FOUND_R:
			if (input == 'a') return FOUND_A3;
			break;
		case FOUND_ALEXADEVORA:
			if (input == 'a') return ACCEPT;
			break;
		default:
			return current;

	}
	return START; //returns to start if there are no valid transitions
}

bool searchString(const std::string& input) {
	State currentState = START;
	for (char c : input) {

		//imma work on this later imma play marvel rivals
	}
}