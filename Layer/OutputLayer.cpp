//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayer.h"
#include "../Neuron/OutputLayerNeuron.h"
#include <iostream>
#include "math.h"
OutputLayer::OutputLayer(int layerId,RN & targetValues){
    setLayerId(layerId);
    std::cout << "L"<<layerId<< std::endl;
    for(int i=0;i<targetValues.size();++i){
        auto n = std::make_shared<OutputLayerNeuron>(layerId,i,targetValues[i]);
        d_neurons.push_back(n);
    }
}
double OutputLayer::computeError(){//
    double res=0.;
    for(auto n : d_neurons){
        double e=n->computeError();
        res+=e*e;
    }
    return res/2./d_neurons.size();
}