//
// Created by jbmdu on 08/04/2018.
//

#include "GenericNeuron.h"
#include <iostream>

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

}

GenericNeuron::GenericNeuron(GenericNeuron *g) {

}

void GenericNeuron::setNeuronId(int neuronId) {
    d_neuronId = neuronId;
}

int GenericNeuron::getNeuronId() {
    return d_neuronId;
}

void GenericNeuron::setLayerId(int layerId) {
    std::cout << "setLayerId" << layerId << std::endl;
    d_layerId = layerId;
}

int GenericNeuron::getLayerId() {
    return d_layerId;
}
void GenericNeuron::setOutput(double output){

};
int GenericNeuron::getOutput(){

}
void GenericNeuron::computeOutput() {
    double res=0.;
    for(auto c : d_backConnections){
        res+= c.getWeight()*c.getFrom()->getOutput();
    }

}