//
// Created by jbmdu on 08/04/2018.
//

#include <iostream>
#include "InputLayerNeuron.h"

void  InputLayerNeuron::setInput(double input){
    d_input=input;
    setOutput(input);
}

InputLayerNeuron::InputLayerNeuron(int neuronId,double input){
    setInput(input);
    setLayerId(0);
    setNeuronId(neuronId);

}
double InputLayerNeuron::getInput() const {
    return d_input;
}
double InputLayerNeuron::computeOutput() {
    return d_input;
}