//
// Created by jbmdu on 08/04/2018.
//

#include <iostream>
#include "HiddenLayer.h"
#include "../Neuron/HiddenLayerNeuron.h"

HiddenLayer::HiddenLayer(int layerId,int layerSize){
    setLayerId(layerId);
    std::cout << "L"<<layerId<< std::endl;

    for(int i=0;i<layerSize;++i){
        auto nn=std::make_shared<HiddenLayerNeuron>(layerId,i);
        d_neurons.push_back(nn);
    }
};