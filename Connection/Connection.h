//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUT_H
#define NN_INPUT_H

#include <memory>
class GenericNeuron;

class Connection {

    std::shared_ptr<GenericNeuron> d_from;
    std::shared_ptr<GenericNeuron> d_to;
    double d_weight;
};


#endif //NN_INPUT_H
