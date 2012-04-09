/*
 *  Settings.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/5/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

class Settings {
    public:
        Settings();
        static Settings& get();
        double devicePixelRatio;
};

#endif