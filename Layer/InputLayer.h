//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUTLAYER_H
#define NN_INPUTLAYER_H

#include "GenericLayer.h"
#include "../Global/Declarations.h"
#include "../Neuron/InputLayerNeuron.h"

class InputLayer : public GenericLayer {
public:
    explicit InputLayer(RN & inputValues);
    void updateOutput() ;
};


#endif //NN_INPUTLAYER_H
