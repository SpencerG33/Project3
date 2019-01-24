//
// Created by greco on 11/12/2018.
//

#ifndef PROJECT3_ALBUMINSTANCES_HPP
#define PROJECT3_ALBUMINSTANCES_HPP
#include <iostream>
#include <vector>
#include "../Pair.hpp"
using namespace std;


class AlbumInstances {
public:
    AlbumInstances();
    void addAttribute(Pair *p);
    void print();

private:
    vector<Pair *> *entityAttributes;


};


#endif //PROJECT3_ALBUMINSTANCES_HPP
