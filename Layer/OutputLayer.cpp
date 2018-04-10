//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayer.h"
#include "../Neuron/OutputLayerNeuron.h"
#include <iostream>
#include "math.h"
OutputLayer::OutputLayer(int layerId,RN & targetValues):GenericLayer(layerId){
    std::cout << "L"<<layerId<< std::endl;
    for(int i=0;i<targetValues.size();++i){
        auto n = std::make_shared<OutputLayerNeuron>(layerId,i,targetValues[i]);
        d_neurons.push_back(n);
    }
}
Types::R OutputLayer::computeError(){//
    R res=0.;
    for(auto n : d_neurons){
        R e=n->computeError();
        res+=e*e;
    }
    return res/2./d_neurons.size();
}