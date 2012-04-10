/*
 *  libwittek.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LIBWITTEK_H_
#define _LIBWITTEK_H_

#include <string>

#define DEBUG 1
void debug(const std::string & s);
void debug(const int & b);

class ResourceException {
    public:
        ResourceException(std::string source, std::string explanation = "");
        const char* what() const throw();
    private:
        std::string source;
};


std::string toLower(std::string orig);

bool contains(const std::string& s, const std::string& query);
bool containsFromEnd(const std::string& s, const std::string& query);


#endif
