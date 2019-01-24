//
// Created by greco on 11/4/2018.
//
#include <string>
using namespace std;

#ifndef PROJECT3_PAIR_HPP
#define PROJECT3_PAIR_HPP


class Pair {
public:
    Pair();
    Pair(string attributeName, string attributeValue);
    Pair(string attributeName, int);
    bool &isNumber();
    int &numberValue();
    string &stringValue();
    string &attributeName();
    int &intName();



private:
    string _attributeName, _attributeStringValue;
    int _intName, _intValue;
    int _attributeNumberValue;
    bool _isNumber, _isBad;
};


#endif //PROJECT3_PAIR_HPP
