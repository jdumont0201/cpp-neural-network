//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayerNeuron.h"

OutputLayerNeuron::OutputLayerNeuron(int layerId,int neuronId,double target){
    setTarget(target);
    setLayerId(layerId);
    setNeuronId(neuronId);
}

void OutputLayerNeuron::setTarget(double target){
    d_target=target;
}