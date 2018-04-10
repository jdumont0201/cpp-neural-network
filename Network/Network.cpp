//
// Created by jbmdu on 08/04/2018.
//
#include "Network.h"
#include "../Global/Types.h"
#include <cassert>
#include <iostream>

Network::Network(RN &inputValues, RN &targetValues, NN &layersSize) {
    init(inputValues, targetValues, layersSize);
}

void Network::init(RN &inputValues, RN &targetValues, NN &layersSize) {
    std::cout << "Initializing network" << std::endl;
    std::cout << "Layers=[ ";for(auto x : layersSize) std::cout<<x<<" ";std::cout<<"]"<< std::endl;
    std::cout << "Targets=[ ";for(auto x : targetValues) std::cout<<x<<" ";std::cout<<"]"<< std::endl;
    std::cout << "Inputs=[ ";for(auto x : inputValues) std::cout<<x<<" ";std::cout<<"]"<< std::endl;

    assert(!inputValues.empty());
    assert(!targetValues.empty());
    assert(layersSize.size() > 2);
    assert(layersSize[0] == inputValues.size());
    assert(layersSize.back() == targetValues.size());

    d_inputValues = inputValues;
    d_targetValues = targetValues;
    d_layersSize = layersSize;

    createLayers();
    linkNeurons();
}

void Network::createLayers() {
    createInputLayer();
    createHiddenLayers();
    createOutputLayer();
}

void Network::createOutputLayer() {
    //output layer
    OutputLayer outputLayer1(d_layers.size(), d_targetValues);
    auto outputLayer2 = std::make_shared<OutputLayer>(outputLayer1);
    d_layers.push_back(outputLayer2);
}
void Network::createInputLayer() {
    //initial layer
    InputLayer inputLayer1(d_inputValues);
    auto inputLayer2 = std::make_shared<InputLayer>(inputLayer1);
    //d_layers.push_back(inputLayer1);
    d_layers.push_back(inputLayer2);
}

void Network::createHiddenLayers() {
    //hidden layers
    for (int i = 1; i < d_layersSize.size() - 1; ++i) {
        HiddenLayer hiddenLayer1(d_layers.size(), d_layersSize[i]);
        auto hiddenLayer2 = std::make_shared<HiddenLayer>(hiddenLayer1);
        d_layers.push_back(hiddenLayer2);
    }
}
void Network::linkNeurons() {
    std::shared_ptr<GenericLayer> prevLayer;
    for (auto l : d_layers) {
        if (prevLayer)
            l->linkNeuronsBackwards(prevLayer);
        prevLayer = l;
    }


}
std::vector<std::shared_ptr<GenericLayer>> Network::getLayers() const {
    return d_layers;
}
std::shared_ptr<GenericLayer> Network::getLayer(int j) const {
    assert(j<d_layers.size());
    return d_layers[j];
}
std::shared_ptr<GenericNeuron> Network::getNeuron(int j,int i) const {
    assert(j<d_layers.size() );
    return d_layers[j]->getNeuron(i);
}
void Network::updateOutput() {
    for (int i=0;i<d_layers.size();++i) {
        d_layers[i]->updateOutput();
    }
}
std::ostream &operator<<(std::ostream &os, const Network &c){
    os << "-----------------------\n";
    for (auto x : c.getLayers()) {
        os << *x ;
    }
    return os;
}
Types::R Network::computeError() {

    return d_layers.back()->computeError();
}

int Network::getNbLayers() const{
    return d_layers.size();
}

Types::R Network::getTargetValue(int i) {
    assert(i < d_targetValues.size());
    return d_targetValues[i];
}

std::shared_ptr<GenericLayer> Network::getLastLayer() const {
    return d_layers[getNbLayers()-1];
}

std::shared_ptr<GenericLayer> Network::operator[](int i) const{
    return d_layers[i];
}