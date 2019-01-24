
// Json to Html.
// Project 3
// Created By Spencer Greco
//


#include <iostream>
#include <fstream>
#include <string>
#include "Tokenizer.hpp"
#include "Parser.hpp"
#include "Albums/Album.hpp"
#include "Tracks/Track.hpp"
#include "Albums/AlbumInstances.hpp"
#include "Tracks/TrackInstance.hpp"
#include "Artists/Artist.hpp"
#include "Artists/ArtistInstance.hpp"
#include <iomanip>

using namespace std;

//This code essentially does the same thing three different times for the three different input files.
// The first section of code is set up the same way as the following to.
// It clears whatever is in tbe file the reads from the template file line by line.
// When or if hit hits the trigger line "{% artists %}", "{% album %}" or "{% track %}"
// it then writes out all of the json information as HTML. The program will produce three
// output files one for track, album, and artist.

int main() {
    fstream ArtistOutput;
    ArtistOutput.open("ArtistOutput.html", ios::out); // Clears file.
    ArtistOutput.close();
    string Artistsline;
    ifstream ArtistTemplateFile ("ArtistTemplate");
    while (!ArtistTemplateFile.eof()) { // Reads from template
        getline(ArtistTemplateFile, Artistsline);
        if (Artistsline == "{% artists %}") { //Trigger line
            ArtistOutput.open("ArtistOutput.html", ios::app);
            ArtistOutput << "<ol>" << endl;
            ArtistOutput.close();
            string ArtistsFile = "artists.txt";
            ifstream artistsFile;
            artistsFile.open(ArtistsFile, ios::in);
            if (!artistsFile) {
                cout << "Unable to open file";
                exit(1); // terminate with error
            }
            artistsFile.close();
            Artist artist;
            ArtistInstance *artistInstance;
            Tokenizer ArtistsTokenizer(ArtistsFile);
            Parser ArtistsParser(ArtistsTokenizer);
            Token ArtistsToken = ArtistsTokenizer.getToken();
            if (!ArtistsToken.isOpenBracket()) {
                cout << "input file should start with a [ ... Terminating " << endl;
                exit(2);
            }
            artistInstance = ArtistsParser.parseJSONObject();
            artist = ArtistsParser.parseJSONEntity(artistInstance, artist); //Builds internal representation
            ArtistsToken = ArtistsTokenizer.getToken();
            while (ArtistsToken.isComma()) {
                artistInstance = ArtistsParser.parseJSONObject();
                artist = ArtistsParser.parseJSONEntity(artistInstance, artist);

                ArtistsToken = ArtistsTokenizer.getToken();
            }
            artist.getInstance(); // Prints out to file
            cout << endl << "done, go to ArtistOutput.html to see results" << endl;
            ArtistOutput.open("ArtistOutput.html", ios::app);
            ArtistOutput << "</ol>" << endl;
            ArtistOutput.close();
        }
        else { //Prints to file if not a trigger line
            ArtistOutput.open("ArtistOutput.html", ios::app);
            ArtistOutput << Artistsline << endl;
            ArtistOutput.close();
        }
    }
    ArtistTemplateFile.close();



    //Albums section
    fstream AlbumsOutput;
    AlbumsOutput.open("AlbumsOutput.html", ios::out);
    AlbumsOutput.close();

    string Albumsline;
    ifstream AlbumTemplateFile ("AlbumTemplate");
    while (!AlbumTemplateFile.eof()) {
        getline(AlbumTemplateFile, Albumsline);
        if (Albumsline == "{% album %}") {
            AlbumsOutput.open("AlbumsOutput.html", ios::app);
            AlbumsOutput << "<ol>" << endl;
            AlbumsOutput.close();
            string AlbumsFile = "Albums.txt";
            ifstream albumFile;
            albumFile.open(AlbumsFile, ios::in);
            if (!albumFile) {
                cout << "Unable to open file";
                exit(1); // terminate with error
            }
            albumFile.close();
            Album album;
            AlbumInstances *albumInstances;
            Tokenizer AlbumsTokenizer(AlbumsFile);
            Parser AlbumsParser(AlbumsTokenizer);
            Token AlbumsToken = AlbumsTokenizer.getToken();
            if (!AlbumsToken.isOpenBracket()) {
                cout << "input file should start with a [ ... Terminating " << endl;
                exit(2);
            }
            albumInstances = AlbumsParser.parse2JSONObject();
            album = AlbumsParser.parse2JSONEntity(albumInstances, album);
            AlbumsToken = AlbumsTokenizer.getToken();
            while (AlbumsToken.isComma()) {
                albumInstances = AlbumsParser.parse2JSONObject();
                album = AlbumsParser.parse2JSONEntity(albumInstances, album);

                AlbumsToken = AlbumsTokenizer.getToken();
            }
            album.getInstance();
            cout << endl << "done, go to AlbumsOutput.html to see results" << endl;
            AlbumsOutput.open("AlbumsOutput.html", ios::app);
            AlbumsOutput << "</ol>" << endl;
            AlbumsOutput.close();
            }

        else {
            AlbumsOutput.open("AlbumsOutput.html", ios::app);
            AlbumsOutput << Albumsline << endl;
            AlbumsOutput.close();
        }
    }
    AlbumTemplateFile.close();

    //Tracks
    fstream TrackOutput;
    TrackOutput.open("TrackOutput.html", ios::out);
    TrackOutput.close();
    string Trackline;
    ifstream TrackTemplateFile ("TrackTemplate");
    while (!TrackTemplateFile.eof()) {
        getline(TrackTemplateFile, Trackline);
        if (Trackline == "{% track %}") {

            TrackOutput.open("TrackOutput.html", ios::app);
            TrackOutput << "<ol>" << endl;
            TrackOutput.close();
            string TracksFile = "Tracks.txt";
            ifstream trackFile;
            trackFile.open(TracksFile, ios::in);
            if (!trackFile) {
                cout << "Unable to open file";
                exit(1); // terminate with error
            }
            trackFile.close();
            Track track;
            TrackInstance *trackInstance;
            Tokenizer TracksTokenizer(TracksFile);
            Parser TracksParser(TracksTokenizer);
            Token TracksToken = TracksTokenizer.getToken();
            if (!TracksToken.isOpenBracket()) {
                cout << "input file should start with a [ ... Terminating " << endl;
                exit(2);
            }

            trackInstance = TracksParser.parse3JSONObject();
            track = TracksParser.parse3JSONEntity(trackInstance, track);
            TracksToken = TracksTokenizer.getToken();

            while (TracksToken.isComma()) {
                trackInstance = TracksParser.parse3JSONObject();
                track = TracksParser.parse3JSONEntity(trackInstance, track);

                TracksToken = TracksTokenizer.getToken();
            }
            track.getInstance();
            cout << endl << "done, go to TrackOutput.html to see results" << endl;

            TrackOutput.open("TrackOutput.html", ios::app);
            TrackOutput << "</ol>" << endl;
            TrackOutput.close();
        }
        else {
            TrackOutput.open("TrackOutput.html", ios::app);
            TrackOutput << Trackline << endl;
            TrackOutput.close();
        }
    }
    TrackTemplateFile.close();

    return 0;
}