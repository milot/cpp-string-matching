project(String-Matching-Algorithm)
cmake_minimum_required (VERSION 2.6)
aux_source_directory(. SRC_LIST)
SET(string-matching-algorithm_SOURCES main.cpp StringMatching.cpp Automaton.cpp)
SET(string-matching-algorithm_HEADERS StringMatching.h Automaton.h)

ADD_EXECUTABLE(string-matching-algorithm ${string-matching-algorithm_SOURCES}
    ${string-matching-algorithm_HEADERS_MOC})

# Add C++11 support :)
add_definitions (
    -std=c++11
)
