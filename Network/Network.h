//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_NETWORK_H
#define NN_NETWORK_H

#include <vector>
#include <memory>

#include "../Layer/GenericLayer.h"
#include "../Layer/InputLayer.h"
#include "../Layer/HiddenLayer.h"
#include "../Layer/OutputLayer.h"
#include "../Global/Declarations.h"

class Network {
    std::vector<GenericLayer> d_layers;
    RN d_inputValues;
    RN d_targetValues;
    NN d_layersSize;

public:
    Network(RN inputValues, RN targetValues, NN layersSize) ;
};


#endif //NN_NETWORK_H
