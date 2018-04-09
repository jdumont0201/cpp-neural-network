//
// Created by jbmdu on 08/04/2018.
//

#include "InputLayerNeuron.h"

void  InputLayerNeuron::setInput(double input){
    d_input=input;
}

InputLayerNeuron::InputLayerNeuron(int neuronId,double input){
    setInput(input);
    setLayerId(0);
    setNeuronId(neuronId);

}