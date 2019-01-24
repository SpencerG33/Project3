//
// Created by greco on 11/12/2018.
//

#ifndef PROJECT3_TRACKINSTANCE_HPP
#define PROJECT3_TRACKINSTANCE_HPP
#include <iostream>
#include <vector>
#include "../Pair.hpp"


class TrackInstance {
public:
    TrackInstance();
    void addAttribute(Pair *p);
    void print();


private:
    vector<Pair *> *entityAttributes;

};


#endif //PROJECT3_TRACKINSTANCE_HPP
