//
// Created by jbmdu on 08/04/2018.
//

#include "GenericNeuron.h"
#include <iostream>
#include <cassert>
#include "math.h"
#include "../Algorithm/ActivationFunctions.h"



void GenericNeuron::linkNeuronsBackwards(std::shared_ptr<GenericLayer> prevLayer) {
    for (auto n : prevLayer->getNeurons()) {
        Connection c(n, shared_from_this(), 0.3);
        d_backConnections.push_back(c);
    }
}

GenericNeuron::GenericNeuron(int layerId,int neuronId):d_layerId(layerId),d_neuronId(neuronId){

}
int GenericNeuron::getNeuronId() const {
    return d_neuronId;
}

int GenericNeuron::getLayerId() const {
    return d_layerId;
}

void GenericNeuron::setOutput(R output) {
    d_output = output;

};

Types::R GenericNeuron::getOutput() const {
    return d_output;
}

Types::R GenericNeuron::activationFunction(R x) {
    return ActivationFunctions::sigmoid(x);
}


Types::R GenericNeuron::computeOutput() {
    R soi = computeSumOfInputs();
    return activationFunction(soi);
}

void GenericNeuron::updateOutput() {
    d_output = computeOutput();
}

Types::R GenericNeuron::computeSumOfInputs() {
    R res = 0.;
    for (auto c : d_backConnections) {
        res += c.getWeight() * c.getFrom()->getOutput();
    }
    return res;
}

 std::vector<Connection> &GenericNeuron::getBackConnections()  {
    return d_backConnections;
}


std::ostream &operator<<(std::ostream &os, const GenericNeuron &c) {
    os << "L" << c.getLayerId() << "-N" << c.getNeuronId() << ": output= " << c.getOutput();
    return os;
}

 GenericNeuron::R GenericNeuron::computeError() {
    return 0.;
};
Connection & GenericNeuron::getBackConnection(int i) {
    assert(i<d_backConnections.size());
    return d_backConnections[i];
}