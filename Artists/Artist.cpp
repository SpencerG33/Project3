//
// Created by greco on 11/4/2018.
//

#include "Artist.hpp"
#include "../Pair.hpp"
#include <fstream>
#include <iomanip>



Artist::Artist():  instances{new vector<ArtistInstance*> } {};

void Artist:: addObject(ArtistInstance *p){
    instances->push_back(p);
}

void Artist::getInstance() {
    fstream ArtistOutput;

    for (auto itr: * instances){
        itr->print();

        ArtistOutput.open("ArtistOutput.html", ios::app);
        ArtistOutput << "</ul>" << endl;
        ArtistOutput << "</li>" << endl;
        ArtistOutput.close();
    }

}




