//
// Created by greco on 11/12/2018.
//
#include <fstream>
#include <iomanip>
#include "ArtistInstance.hpp"
using namespace std;

ArtistInstance::ArtistInstance(): _numAttributes(0), entityAttributes{new vector<Pair*> } {};


void ArtistInstance::addAttribute(Pair *p) {
    entityAttributes->push_back(p);
    numAttributes();
};

void ArtistInstance::numAttributes() {
    _numAttributes++;
};


void ArtistInstance::print() {
    fstream ArtistOutput;
    Pair pair;
    int i = 0;
    for (auto itr: * entityAttributes) {
        if(itr->isNumber()) {
            ArtistOutput.open("ArtistOutput.html", ios::app);
            if (i == 0){
                ArtistOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p>" << endl;
                ArtistOutput << "<ul>" << endl;
            }
            ArtistOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->intName() << "</p></li>"<< endl;
            ArtistOutput.close();
            i++;
        }
        else{
            ArtistOutput.open("ArtistOutput.html", ios::app);
            if (i == 0) {
                ArtistOutput << "<li><p>" << itr->attributeName() << "<br>" << itr->stringValue() << "</p>" << endl;
                ArtistOutput << "<ul>" << endl;
            }
            ArtistOutput << "<li><p>" << itr->attributeName() << " <br>" << itr->stringValue() << "</p></li>"<< endl;
            ArtistOutput.close();
            i++;
        }
    }
}


