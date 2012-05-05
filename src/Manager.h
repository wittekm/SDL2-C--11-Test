/*
 * Manager.h
 *
 *  Created on: Apr 12, 2012
 *      Author: max
 */


#ifndef MANAGER_H_
#define MANAGER_H_

#include "includes.h"
#include <map>


template <class Key, class SharedPtr>
class Manager {
    protected:
        // only get() can instantiate it, so protected
        Manager();
        //virtual ~Manager();

    public:

        SharedPtr getObject(const Key&);
        bool hasObject(const Key&);
        void addObject(const Key&, const SharedPtr&);

    protected:
        virtual SharedPtr loadObject(const Key&) = 0;


    private:
// --- Variables ---
        std::map<Key, SharedPtr> objectMap;

        typedef std::pair<Key, SharedPtr> MapPair;
};

// Include cpp file here because it's templated
#include "Manager.cpp"

#endif /* MANAGER_H_ */
