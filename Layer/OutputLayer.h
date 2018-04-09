//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_OUTPUTLAYER_H
#define NN_OUTPUTLAYER_H


#include "GenericLayer.h"
#include "../Global/Declarations.h"
#include "../Neuron/OutputLayerNeuron.h"

class OutputLayer : public GenericLayer {
    std::vector<std::shared_ptr<OutputLayerNeuron>> d_neurons;
public :
    explicit OutputLayer(int layerId, RN &targetValues);

    double computeError();

};


#endif //NN_OUTPUTLAYER_H
