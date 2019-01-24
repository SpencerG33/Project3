//
// Created by greco on 11/4/2018.
//

#ifndef PROJECT3_TOKEN_HPP
#define PROJECT3_TOKEN_HPP


#include <string>
using namespace std;
//interface of the class

class Token {
public:
    Token();
    bool &isOpenBracket();
    bool &isCloseBracket();
    bool &isOpenBrace();
    bool &isCloseBrace();
    bool &isString();
    bool &isColon();
    bool &isComma();
    bool&isInt();
    bool &endOfFile();
    string tagName();
    int IntName();
    void setTagName(string);
    void setIntValue(int);
    void print();



private:
    bool _isOpenBracket, _isCloseBracket, _isOpenBrace, _isCloseBrace, _isString, _isColon, _isInt, _isComma, _eof;

    string _tagName;
    int _intValue;


};


#endif //PROJECT3_TOKEN_HPP
