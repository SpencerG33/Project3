//
// Created by greco on 11/4/2018.
//

#include "Parser.hpp"
#include "Pair.hpp"
using namespace std;

Parser::Parser(Tokenizer &tokenizer): tokenizer(tokenizer) {

};

ArtistInstance * Parser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
//    Entity entity;
    Token token = tokenizer.getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    ArtistInstance *instance = new ArtistInstance();
    do {
        Pair *pair = parseAPair();
        instance->addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}


AlbumInstances * Parser::parse2JSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
//    Entity entity;
    Token token = tokenizer.getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    AlbumInstances *instance = new AlbumInstances();
    do {
        Pair *pair = parseAPair();
        instance->addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

TrackInstance * Parser::parse3JSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
//    Entity entity;
    Token token = tokenizer.getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    TrackInstance *instance = new TrackInstance();
    do {
        Pair *pair = parseAPair();
        instance->addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}





Pair* Parser::parseAPair(){
    Token token;
    Pair *pair = new Pair() ;
    token = tokenizer.getToken();
    if(token.isString())
        pair->attributeName() = token.tagName();
    if (token.isInt())
        pair->numberValue() = token.isInt();
    token = tokenizer.getToken();
    if(token.isColon()){
        token = tokenizer.getToken();
        if(token.isString()) {
            pair->stringValue() = token.tagName();
            return pair;
        }
        if (token.isInt()){
            pair->intName() = token.IntName();
            pair->isNumber() = true;
            return  pair;
        }
    }
    else {
        cout << "Terminating..." << std::endl;
        exit(1);
    }


}


Artist Parser::parseJSONEntity(ArtistInstance *artistInstance,Artist artist){
    artist.addObject(artistInstance);
    return artist;
}

Album Parser::parse2JSONEntity(AlbumInstances *albumInstances,Album album){
    album.addObject(albumInstances);
    return album;
}

Track Parser::parse3JSONEntity(TrackInstance *trackInstance,Track track){
    track.addObject(trackInstance);
    return track;
}