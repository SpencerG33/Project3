//
// Created by student on 11/4/18.
//

#include "Token.hpp"
#include <iostream>
using namespace std;

Token::Token(): _isOpenBracket{false},
                _isCloseBracket{false},
                _isOpenBrace{false},
                _isCloseBrace{false},
                _isString{false},
                _isColon{false},
                _isComma{false},
                _isInt {false},
                _eof(false),
                _intValue(0){}

bool &Token::isOpenBracket() {return _isOpenBracket;}
bool &Token::isCloseBracket() {return _isCloseBracket;}
bool &Token::isOpenBrace() {return _isOpenBrace; }
bool &Token::isCloseBrace() {return _isCloseBrace; }
bool &Token::isString() { return _isString; }
bool &Token::isColon() { return _isColon; }
bool &Token::isComma() { return _isComma; }
bool &Token::isInt() { return _isInt; }
bool &Token::endOfFile() {return _eof; }
string Token::tagName() {return _tagName; }
int Token::IntName() { return _intValue; }
void Token::setTagName(string tag) {
    _tagName = tag;
}
void Token::setIntValue(int intValue) {
    _intValue = intValue;
}
void Token::print() {
    cout << tagName() << endl;
}




