//
// Created by jbmdu on 08/04/2018.
//

#include "GenericLayer.h"
#include <vector>
#include "../Neuron/GenericNeuron.h"

std::vector<std::shared_ptr<GenericNeuron>> GenericLayer::getNeurons() {
    return d_neurons;
}

void GenericLayer::linkNeuronsBackwards(std::shared_ptr<GenericLayer> &prevLayer) {
    for (auto n : d_neurons) {
        n->linkNeuronsBackwards(prevLayer);
    }
}
void GenericLayer::setLayerId(int layerId){
    d_layerId=layerId;
}
int GenericLayer::getLayerId(){
    return d_layerId;
}
void GenericLayer::computeOutput() {
    for (int i=1;i<d_neurons.size();++i) {
        d_neurons[i]->computeOutput();
    }
}