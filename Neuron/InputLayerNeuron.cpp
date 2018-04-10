//
// Created by jbmdu on 08/04/2018.
//

#include <iostream>
#include "InputLayerNeuron.h"

void  InputLayerNeuron::setInput(R input){
    d_input=input;
    setOutput(input);
}

InputLayerNeuron::InputLayerNeuron(int neuronId,R input){
    setInput(input);
    setLayerId(0);
    setNeuronId(neuronId);
    std::cout << "L"<<0<<"-N" <<neuronId<<": create"<< std::endl;

}
Types::R InputLayerNeuron::getInput() const {
    return d_input;
}
Types::R InputLayerNeuron::computeOutput() {
    return d_input;
}