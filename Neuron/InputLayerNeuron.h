//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUTLAYERNEURON_H
#define NN_INPUTLAYERNEURON_H


#include "GenericNeuron.h"

class InputLayerNeuron : public GenericNeuron {
    double d_input;
public:
    void setInput(double input);
    InputLayerNeuron(double input);
};


#endif //NN_INPUTLAYERNEURON_H
