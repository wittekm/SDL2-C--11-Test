/*
 *  Settings.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/5/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

class Settings {
    public:
        Settings();
        static Settings& get();
        double devicePixelRatio;
};

#endif