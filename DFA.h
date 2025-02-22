#pragma once
#ifndef _DFA
#define _DFA

#include <string>


enum Phase {
    MATCH_FIRST,  
    MATCH_LAST,   
    ACCEPT        
};


class DFA {
private:
    std::string firstName; 
    std::string lastName;  
    Phase phase;           
    int idx1;              
    int idx2;             

public:
  
    DFA(const std::string& first, const std::string& last);
   
    void reset();
    
    void processChar(char c);

    bool isAccepted() const;
};


bool searchString(const std::string& input, const std::string& first, const std::string& last);

#endif 
