//
// Created by jbmdu on 08/04/2018.
//

#include <memory>
#include <iostream>
#include "InputLayer.h"
#include "../Neuron/InputLayerNeuron.h"

InputLayer::InputLayer(RN & inputValues):GenericLayer(0){
    std::cout << "L0"<<std::endl;
    for(int i=0;i<inputValues.size();++i){
        auto nn=std::make_shared<InputLayerNeuron>(i,inputValues[i]);
        d_neurons.push_back(nn);
    }
}

void InputLayer::updateOutput() {
    for (int i=0;i<d_neurons.size();++i) {
        d_neurons[i]->updateOutput();
    }
}