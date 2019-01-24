//
// Created by greco on 11/4/2018.
//

#include "Pair.hpp"

Pair::Pair(): _isNumber {false}, _attributeNumberValue(0), _intValue(0) {}
Pair::Pair(string attributeName, int): _isNumber {false}, _isBad{false}, _attributeNumberValue(0), _intValue(0) {}
Pair::Pair(string attributeName, string attributeValue):_isNumber {false}, _isBad{false}, _attributeNumberValue(0), _intValue(0) {
    attributeName = _attributeName;
    attributeValue =  _attributeStringValue;
}


bool &Pair::isNumber() {return _isNumber; }
int &Pair::numberValue() { return _attributeNumberValue; }
string &Pair::stringValue() { return _attributeStringValue; }
string &Pair::attributeName() {return _attributeName; }
int &Pair::intName() { return _intName; }
