//
// Created by greco on 11/4/2018.
//

#include "Track.hpp"
#include <fstream>
#include <iomanip>


Track::Track(): instances{new vector<TrackInstance*> } {};

// This c;ass does all the heavy lifting.
void Track:: addObject(TrackInstance *p){
    instances->push_back(p);
}

void Track::getInstance() {
    fstream TrackOutput;

    for (auto itr: * instances){
        itr->print();
        TrackOutput.open("TrackOutput.html", ios::app);
        TrackOutput << "</ul>" << endl;
        TrackOutput << "</li>" << endl;
        TrackOutput.close();
    }

}
