//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICLAYER_H
#define NN_GENERICLAYER_H

#include <vector>
#include "../Neuron/GenericNeuron.h"

class GenericLayer {
protected :
    std::vector<GenericNeuron> neurons;
};


#endif //NN_GENERICLAYER_H
