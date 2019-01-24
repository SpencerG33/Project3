//
// Created by greco on 11/4/2018.
//

#include <string>
#include <vector>
#include "TrackInstance.hpp"
using namespace std;

#ifndef PROJECT3_TRACK_HPP
#define PROJECT3_TRACK_HPP
#include "../Pair.hpp"

class Track
{
public:
    Track();
    void addObject(TrackInstance* p);
    void getInstance();

private:
    vector<TrackInstance*> *instances;
};

#endif //PROJECT3_TRACK_HPP
