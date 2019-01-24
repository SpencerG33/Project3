//
// Created by greco on 11/4/2018.
//
#include <string>
#include <vector>
#include"ArtistInstance.hpp"
using namespace std;

#ifndef PROJECT3_ARTIST_HPP
#define PROJECT3_ARTIST_HPP

class Pair;


class Artist {
public:
    Artist();
    void addObject(ArtistInstance* p);
    void getInstance();

private:
    vector<ArtistInstance*> *instances; //Vector of pointers.
};


#endif //PROJECT3_ARTIST_HPP
