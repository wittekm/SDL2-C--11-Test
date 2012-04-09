/*
 *  Settings.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/5/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Settings.h"

Settings::Settings() { 

}

Settings& Settings::get() {
    static Settings * instance;
    if(instance == 0)
        instance = new Settings();
    return *instance;
}
