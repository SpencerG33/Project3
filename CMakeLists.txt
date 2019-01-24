cmake_minimum_required(VERSION 3.12)
project(Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3 main.cpp Tracks/Track.cpp Tracks/Track.hpp Albums/Album.cpp Albums/Album.hpp Artists/Artist.cpp Artists/Artist.hpp Pair.cpp Pair.hpp Parser.cpp Parser.hpp Token.cpp Token.hpp Tokenizer.cpp Tokenizer.hpp Albums/AlbumInstances.cpp Albums/AlbumInstances.hpp Tracks/TrackInstance.cpp Tracks/TrackInstance.hpp Artists/ArtistInstance.cpp Artists/ArtistInstance.hpp)