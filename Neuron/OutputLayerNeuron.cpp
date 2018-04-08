//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayerNeuron.h"

OutputLayerNeuron::OutputLayerNeuron(double target){
    setTarget(target);
}

void OutputLayerNeuron::setTarget(double target){
    d_target=target;
}