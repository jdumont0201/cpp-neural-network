//
// Created by jbmdu on 08/04/2018.
//

#include "OutputLayer.h"
#include "../Neuron/OutputLayerNeuron.h"

OutputLayer::OutputLayer(RN targetValues){
    for(double i : targetValues){
        OutputLayerNeuron n;
        Connection c;
        std::vector<Connection> inputs={c};
        n.setInputs(inputs);
        neurons.push_back(n);
    }
}
