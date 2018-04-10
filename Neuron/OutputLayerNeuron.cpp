//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayerNeuron.h"

OutputLayerNeuron::OutputLayerNeuron(int layerId,int neuronId,R target){
    setTarget(target);
    setLayerId(layerId);
    setNeuronId(neuronId);
    std::cout << "L"<<layerId<<"-N" <<neuronId<<": create"<< std::endl;
}

void OutputLayerNeuron::setTarget(R target){
    d_target=target;
}

Types::R OutputLayerNeuron::computeError(){
    return d_target-getOutput();
}