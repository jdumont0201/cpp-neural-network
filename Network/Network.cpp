//
// Created by jbmdu on 08/04/2018.
//

#include "Network.h"
#include <cassert>

Network::Network(RN inputValues, RN targetValues, NN layersSize) {
    assert(!inputValues.empty());
    assert(!targetValues.empty);
    assert(layersSize.size()>2);
    assert(layersSize[0] == inputValues.size());
    assert(layersSize.back() == targetValues.size());

    d_inputValues = inputValues;
    d_targetValues = targetValues;
    d_layersSize = layersSize;

    //initial layer
    InputLayer inputLayer1(inputValues);
    d_layers.push_back(inputLayer1);
    //std::unique_ptr<InputLayer> inputLayer (new InputLayer());
    //d_layers.push_back(std::move(inputLayer));

    //hidden layers
    for (int i = 1; i < layersSize.size()-1; ++i) {
       // std::unique_ptr<HiddenLayer> hiddenLayer(new HiddenLayer());
        HiddenLayer hiddenLayer1;
        d_layers.push_back(hiddenLayer1);
    }

    //output layer
    OutputLayer outputLayer1(targetValues);
    //std::unique_ptr<OutputLayer> outputLayer(new OutputLayer());
    d_layers.push_back(outputLayer1);

    //link neurons
    for (int i = 0; i < layersSize.size(); ++i) {

    }

}