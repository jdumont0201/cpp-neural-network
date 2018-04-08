//
// Created by jbmdu on 08/04/2018.
//

#include "InputLayerNeuron.h"

void  InputLayerNeuron::setInput(double input){
    d_input=input;
}

InputLayerNeuron::InputLayerNeuron(double input){
    setInput(input);
}