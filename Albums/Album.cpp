//
// Created by greco on 11/4/2018.
//

#include "Album.hpp"
#include <fstream>
#include <iomanip>


Album::Album():  instances{new vector<AlbumInstances*> } {};

void Album:: addObject(AlbumInstances *p){
    instances->push_back(p);
}

void Album::getInstance() {
    fstream AlbumsOutput;

    for (auto itr: * instances){
        itr->print();
        AlbumsOutput.open("AlbumsOutput.html", ios::app);
        AlbumsOutput << "</ul>" << endl;
        AlbumsOutput << "</li>" << endl;
        AlbumsOutput.close();
    }

}

