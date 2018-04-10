//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_OUTPUTLAYER_H
#define NN_OUTPUTLAYER_H


#include "GenericLayer.h"
#include "../Global/Types.h"
#include "../Neuron/OutputLayerNeuron.h"

class OutputLayer : public GenericLayer {
    typedef Types::R R;
    typedef Types::RN RN;

public :
    explicit OutputLayer(int layerId, RN &targetValues);

    R  computeError();

};


#endif //NN_OUTPUTLAYER_H
