/*
 * Label.h
 *
 *  Created on: Apr 10, 2012
 *      Author: max
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "includes.h"

class Label : public Paintable {
public:
    Label(const std::string& text, const std::string& font);
    virtual void paint();

private:
    TextureShared tex;

};

#endif /* LABEL_H_ */
