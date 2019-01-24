//
// Created by greco on 11/4/2018.
//

#ifndef PROJECT3_PARSER_HPP
#define PROJECT3_PARSER_HPP
#include "Pair.hpp"
#include "Tokenizer.hpp"
#include "Albums/AlbumInstances.hpp"
#include "Artists/ArtistInstance.hpp"
#include "Tracks/TrackInstance.hpp"
#include "Tracks/Track.hpp"
#include "Albums/Album.hpp"
#include "Artists/Artist.hpp"

class Parser {
public:Parser(Tokenizer &tokenizer);

    //This file holds the parser functions for Album, Artists, and track
    // Using pointers.

    Pair *parseAPair();
    ArtistInstance *parseJSONObject();
    AlbumInstances *parse2JSONObject();
    TrackInstance *parse3JSONObject();
    Artist parseJSONEntity(ArtistInstance*, Artist);
    Album parse2JSONEntity(AlbumInstances*, Album);
    Track parse3JSONEntity(TrackInstance*, Track);

private:
    Tokenizer &tokenizer;
};



#endif //PROJECT3_PARSER_HPP
