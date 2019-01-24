//
// Created by greco on 11/12/2018.
//

#include "AlbumInstances.hpp"
#include <iostream>
#include <fstream>

using namespace std;

AlbumInstances::AlbumInstances():  entityAttributes{new vector<Pair*> } {};


void AlbumInstances::addAttribute(Pair *p) {
    entityAttributes->push_back(p);
};





void AlbumInstances::print() {
    fstream AlbumsOutput;
    Pair pair;
    int i = 0;
    for (auto itr: * entityAttributes) {
        if(itr->isNumber()) {
            AlbumsOutput.open("AlbumsOutput.html", ios::app);
            if (i == 0){
                AlbumsOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p>" << endl;
                AlbumsOutput << "<ul>" << endl;
            }
            AlbumsOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p></li>"<< endl;
            AlbumsOutput.close();
            i++;
        }
        else{
            AlbumsOutput.open("AlbumsOutput.html", ios::app);
            if (i == 0) {
                AlbumsOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->stringValue() << "</p>" << endl;
                AlbumsOutput << "<ul>" << endl;
            }
            AlbumsOutput << "<li><p>" << itr->attributeName() << " <br>" << itr->stringValue() << "</p></li>"<< endl;
            AlbumsOutput.close();
            i++;
        }
    }
}

