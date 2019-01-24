//
// Created by greco on 11/12/2018.
//

#ifndef PROJECT3_ARTISTINSTANCE_HPP
#define PROJECT3_ARTISTINSTANCE_HPP

#include <iostream>
#include <vector>
#include "../Pair.hpp"
using namespace std;

class ArtistInstance {
public:
    ArtistInstance();
    void addAttribute(Pair *p);
    void numAttributes();
    void print();



private:
    vector<Pair *> *entityAttributes;
    int _numAttributes;

};


#endif //PROJECT3_ARTISTINSTANCE_HPP
