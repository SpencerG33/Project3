//
// Created by greco on 11/4/2018.
//

#ifndef PROJECT3_TOKENIZER_HPP
#define PROJECT3_TOKENIZER_HPP

#include <fstream>
#include <string>
#include "Token.hpp"
using namespace std;

class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();


private:
    string fileName;
    ifstream inputStream;
    bool charOfInterest(char c);
};


#endif //PROJECT3_TOKENIZER_HPP
