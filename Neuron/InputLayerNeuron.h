//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUTLAYERNEURON_H
#define NN_INPUTLAYERNEURON_H


#include "GenericNeuron.h"

class InputLayerNeuron : public GenericNeuron {
    typedef Types::R R;
    R d_input;
public:
    void setInput(R input);
    R getInput() const;
    InputLayerNeuron(int neuronId,R input);
    R computeOutput();
};


#endif //NN_INPUTLAYERNEURON_H
