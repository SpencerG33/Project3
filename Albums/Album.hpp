//
// Created by greco on 11/4/2018.
//

#include <string>
#include <vector>
#include "AlbumInstances.hpp"
using namespace std;

#ifndef PROJECT3_ALBUM_HPP
#define PROJECT3_ALBUM_HPP


class Pair;

class Album
{
public:
    Album();
    void addObject(AlbumInstances* p);
    void getInstance();


private:
    vector<AlbumInstances*> *instances;
};


#endif //PROJECT3_ALBUM_HPP
