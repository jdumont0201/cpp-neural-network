//
// Created by jbmdu on 08/04/2018.
//

#include "GenericNeuron.h"
#include <iostream>
#include "math.h"
#include "../Algorithm/ActivationFunctions.h"

void GenericNeuron::setInputs(std::vector<Connection> backConnections) {
    d_backConnections = backConnections;
}


void GenericNeuron::linkNeuronsBackwards(std::shared_ptr<GenericLayer> prevLayer) {
    for (auto n : prevLayer->getNeurons()) {
        Connection c(n, shared_from_this(), 0.3);
        d_backConnections.push_back(c);
    }
}

GenericNeuron::GenericNeuron() {
    std::cout << "+N" << std::endl;
    d_output = -1;
}

GenericNeuron::GenericNeuron(GenericNeuron *g) {

}

void GenericNeuron::setNeuronId(int neuronId) {
    d_neuronId = neuronId;
}

int GenericNeuron::getNeuronId() const {
    return d_neuronId;
}

void GenericNeuron::setLayerId(int layerId) {
    d_layerId = layerId;
}

int GenericNeuron::getLayerId() const {
    return d_layerId;
}

void GenericNeuron::setOutput(double output) {
    d_output = output;

};

double GenericNeuron::getOutput() const {
return d_output;
}

double GenericNeuron::activationFunction(double x) {
    return ActivationFunctions::sigmoid(x);
}
double GenericNeuron::activationFunctionDerivative(double x) {
    return ActivationFunctions::derivative_sigmoid(x);
}

double GenericNeuron::computeOutput() {

    double soi = computeSumOfInputs();
    std::cout << "L" << d_layerId << "-N" << d_neuronId << "soi " << soi << std::endl;
    return activationFunction(soi);
}

void GenericNeuron::updateOutput() {
    d_output = computeOutput();
}

double GenericNeuron::computeSumOfInputs() {
    double res = 0.;
    for (auto c : d_backConnections) {
        std::cout << c << std::endl;
        res += c.getWeight() * c.getFrom()->getOutput();
    }
    return res;
}

const std::vector<Connection> &GenericNeuron::getBackConnections() const {
    return d_backConnections;
}

void GenericNeuron::setD_backConnections(const std::vector<Connection> &d_backConnections) {
    GenericNeuron::d_backConnections = d_backConnections;
}

std::ostream& operator<<(std::ostream& os, const GenericNeuron& c){
    os << "L" << c.getLayerId() << "-N" << c.getNeuronId() << ": output= " << c.getOutput();
    return os;
}
