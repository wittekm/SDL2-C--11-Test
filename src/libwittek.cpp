/*
 *  libwittek.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
 
#include "libwittek.h"
#include <iostream>
#include <algorithm>
using std::transform;
using std::string;


void debug(const string & s) {
    if(DEBUG)
        std::cout << s << std::endl;
}

void debug(const int & b) {
    if(DEBUG)
        std::cout << b << std::endl;
}

ResourceException::ResourceException(const string& source, const string& explanation) :
std::runtime_error(source + ": " + explanation) { }

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), tolower);
    return s;
}

bool contains(const string& s, const string& query) {
    return s.find(query) != string::npos;
}

bool containsFromEnd(const string& s, const string& query) {
    assert(false); // don't use this it doesn't work for some crazy reason
    return s.find_last_of(query) != string::npos;
}
