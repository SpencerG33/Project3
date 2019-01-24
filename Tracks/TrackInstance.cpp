//
// Created by greco on 11/12/2018.
//

#include "TrackInstance.hpp"
#include <iostream>
#include <fstream>
using namespace std;

TrackInstance::TrackInstance(): entityAttributes{new vector<Pair*> } {};


void TrackInstance::addAttribute(Pair *p) {
    entityAttributes->push_back(p);

};





void TrackInstance::print() {
    fstream TrackOutput;
    Pair pair;
    int i = 0;
    for (auto itr: * entityAttributes) {
        if(itr->isNumber()) {
            TrackOutput.open("TrackOutput.html", ios::app);
            if (i == 0){
                TrackOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p>" << endl;
                TrackOutput << "<ul>" << endl;
            }
            TrackOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p></li>"<< endl;
            TrackOutput.close();
            i++;
        }
        else{
            TrackOutput.open("TrackOutput.html", ios::app);
            if (i == 0) {
                TrackOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->stringValue() << "</p>" << endl;
                TrackOutput << "<ul>" << endl;
            }
            TrackOutput << "<li><p>" << itr->attributeName() << " <br>" << itr->stringValue() << "</p></li>"<< endl;
            TrackOutput.close();
            i++;
        }
    }
}
