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
using std::string;


void debug(const string & s) {
    if(DEBUG)
        std::cout << s << std::endl;
}

void debug(const int & b) {
    if(DEBUG)
        std::cout << b << std::endl;
}

ResourceException::ResourceException(std::string source, std::string explanation) {
    this->source = source;
}

const char* ResourceException::what() const throw() {
    return source.c_str();
}