//
// Created by jbmdu on 08/04/2018.
//

#include "GenericLayer.h"
#include <vector>
#include "../Neuron/GenericNeuron.h"

std::vector<std::shared_ptr<GenericNeuron>> GenericLayer::getNeurons() const {
    return d_neurons;
}

void GenericLayer::linkNeuronsBackwards(std::shared_ptr<GenericLayer> &prevLayer) {
    for (auto n : d_neurons) {
        n->linkNeuronsBackwards(prevLayer);
    }
}

void GenericLayer::setLayerId(int layerId) {
    d_layerId = layerId;
}

int GenericLayer::getLayerId() {
    return d_layerId;
}

double GenericLayer::computeError() {
    return 0.;
}
void GenericLayer::updateOutput() {
    for (auto n : d_neurons) {
        n->updateOutput();
    }
}

std::ostream &operator<<(std::ostream &os, const GenericLayer &c) {
    for (auto n : c.getNeurons()) {
        os << *n << "\n";
    }
    return os;
}
int GenericLayer::getSize() const{
    return d_neurons.size();
}