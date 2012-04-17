/*
 * Label.h
 *
 *  Created on: Apr 10, 2012
 *      Author: max
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "SDL.h"
#include "GameObject.h"
#include "includes.h"

class Label : public GameObject {
public:
    Label(const std::string& text, const std::string& font);
};

#endif /* LABEL_H_ */
