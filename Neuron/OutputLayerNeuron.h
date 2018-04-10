//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_OUTPUTLAYERNEURON_H
#define NN_OUTPUTLAYERNEURON_H


#include "GenericNeuron.h"

class OutputLayerNeuron : public GenericNeuron {
    typedef Types::R R;
    const R d_target;
public:
    OutputLayerNeuron(int layerId,int neuronId,R target);
    R computeError();
};


#endif //NN_OUTPUTLAYERNEURON_H
