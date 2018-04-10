//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_DECLARATIONS_H
#define NN_DECLARATIONS_H

#include <vector>
#include "ddouble.h"

struct Types {
    typedef ddouble R;
    typedef std::vector<R> RN;
    typedef std::vector<std::vector<R>> RNM;
    typedef std::vector<int> NN;
};


#endif //NN_DECLARATIONS_H
