/*
 *  libwittek.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef LIBWITTEK_H_
#define LIBWITTEK_H_

#include <string>
#include <cassert>
#include <stdexcept>

#define DEBUG 1
void debug(const std::string & s);
void debug(const int & b);

class ResourceException : public std::runtime_error {
public:
    ResourceException(const std::string& source, const std::string& explanation = "");
};

// Inheritable Singleton


template <class T>
class Singleton
{
    public:
        static T * get();
        static void set(T*);
    protected:
        Singleton() { };
        virtual ~Singleton() { };
    private:
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
        static T* instance;
};


template <class T>
T* Singleton<T>::get()
{
    return instance ? instance : (instance = new T);
}

template <class T>
void Singleton<T>::set(T* t)
{
    if(!instance)
        instance = t;
}

template <class T>
T* Singleton<T>::instance = 0;


// An aborted singleton class that can take a constructor (kinda) as a parameter
/*
template <class T, class Init>
class Singleton
{
    public:
        static T * get();

    protected:
        Singleton(Init initFunction);
        ~Singleton();
    private:
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
        static T* instance;

    friend class CApp;
};

template <class T, class Init>
Singleton<T, Init>::Singleton(Init initFunction)
{
    if(!instance) {
        instance = initFunction();
    }
}
template <class T, class Init> T* Singleton<T, Init>::instance = 0;

template <class T, class Init>
Singleton<T, Init>::~Singleton() { }

template <class T, class Init>
T* Singleton<T, Init>::get() { return instance; }
*/


// Random useful stuff
std::string toLower(std::string orig);

bool contains(const std::string& s, const std::string& query);
bool containsFromEnd(const std::string& s, const std::string& query);


#endif
