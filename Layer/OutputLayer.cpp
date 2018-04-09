//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayer.h"
#include "../Neuron/OutputLayerNeuron.h"
#include <iostream>

OutputLayer::OutputLayer(int layerId,RN & targetValues){
    setLayerId(layerId);
    std::cout << "L"<<layerId<< std::endl;
    for(int i=0;i<targetValues.size();++i){
        auto n = std::make_shared<OutputLayerNeuron>(layerId,i,targetValues[i]);
        d_neurons.push_back(n);
    }
}
