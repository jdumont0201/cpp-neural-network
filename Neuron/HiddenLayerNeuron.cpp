//
// Created by jbmdu on 08/04/2018.
//

#include "HiddenLayerNeuron.h"

HiddenLayerNeuron::HiddenLayerNeuron(int layerId,int neuronId):GenericNeuron(layerId, neuronId){
    std::cout << "L"<<layerId<<"-N" <<neuronId<<": create"<< std::endl;
}