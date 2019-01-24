// Created by Spencer Greco on 11/4/18.
//

#include "Tokenizer.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
Tokenizer::Tokenizer(string name): fileName{name}
{
    inputStream.open(fileName, std::ios::in);
}


bool Tokenizer::charOfInterest(char c) { // These are the characters that the program is looking for
    if(c == '[' || c == ']' || c == '{'|| c == '}'|| c == '"'|| c == ':'||c == ',' ||  isdigit(c))
        return true;
    return false;
}

Token Tokenizer::getToken() { //Large function that give the tokens the needed information to make the program work correctly.

    char c;

    if (!inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << fileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && !charOfInterest(c)) { //Counts Line Number and Character number
    }

    // inputStream.get(c);

    Token token;
    if (inputStream.eof()) {
        token.endOfFile() = true;
        return token;
    }

    else if (c == '[') {
        token.isOpenBracket() = true;
        string tag = "[";
        token.setTagName(tag);
        return token;
    }

    else if (c == ']') {
        token.isCloseBracket() = true;
        string tag = "]";
        token.setTagName(tag);
        return token;
    }

    else if (c == '{') {
        token.isOpenBrace() = true;
        string tag = "{";
        token.setTagName(tag);
        return token;
    }

    else if (c == '}') {
        token.isCloseBrace() = true;
        string tag = "}";
        token.setTagName(tag);
        return token;
    }

    else if (c == '"'){
        token.isString() = true;
        string tag;
        while (inputStream.get(c) && c != '"') {
            tag += c;
            char back = tag.back();
            inputStream.get(c);

            if (back == '\\' && c == '"' ) {
                tag.back() = '"';
                inputStream.get(c);
            }
            inputStream.putback(c);
        }

        token.setTagName(tag);

        return token;
    }

    else if(c == ':'){
        token.isColon() = true;
        string tag = ":";
        token.setTagName(tag);
        return token;
    }

    else if (c == ',') {
        token.isComma() = true;
        string tag = ",";
        token.setTagName(tag);
        return token;
    }
    else if( isdigit(c)){
        token.isInt() = true;
        int num;
        inputStream.putback(c);
        inputStream >> num;
        token.setIntValue(num);
        return token;
    }
    else
        return token;
}





