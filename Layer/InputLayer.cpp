//
// Created by jbmdu on 08/04/2018.
//

#include "InputLayer.h"
#include "../Neuron/InputLayerNeuron.h"

InputLayer::InputLayer(RN inputValues){
    for(double i : inputValues){
        InputLayerNeuron n;
        n.setInput(i);
        neurons.push_back(n);
    }
}