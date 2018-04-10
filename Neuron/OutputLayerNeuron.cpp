//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayerNeuron.h"

OutputLayerNeuron::OutputLayerNeuron(int layerId,int neuronId,R target):d_target(target),GenericNeuron(layerId,neuronId){

    std::cout << "L"<<layerId<<"-N" <<neuronId<<": create"<< std::endl;
}

Types::R OutputLayerNeuron::computeError(){
    return d_target-getOutput();
}