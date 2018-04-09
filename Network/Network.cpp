//
// Created by jbmdu on 08/04/2018.
//
#include "Network.h"
#include "../Global/Declarations.h"
#include <cassert>
#include <iostream>

Network::Network(RN &inputValues, RN &targetValues, NN &layersSize) {
    init(inputValues, targetValues, layersSize);
}

void Network::init(RN &inputValues, RN &targetValues, NN &layersSize) {
    std::cout << "Initializing network" << std::endl;
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
double Network::computeError() {

    return d_layers.back()->computeError();
}

int Network::getNbLayers() {
    return d_layers.size();
}

double Network::getTargetValue(int i) {
    return d_targetValues[i];
}
