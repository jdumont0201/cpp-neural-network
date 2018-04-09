//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_HIDDENLAYERNEURON_H
#define NN_HIDDENLAYERNEURON_H


#include "GenericNeuron.h"

class HiddenLayerNeuron : public GenericNeuron {
public:
    HiddenLayerNeuron(int layerId,int neuronId);
};


#endif //NN_HIDDENLAYERNEURON_H
