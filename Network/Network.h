//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_NETWORK_H
#define NN_NETWORK_H

#include <vector>
#include <memory>

#include "../Layer/GenericLayer.h"
#include "../Layer/InputLayer.h"
#include "../Layer/HiddenLayer.h"
#include "../Layer/OutputLayer.h"
#include "../Global/Types.h"

class Network {
    typedef Types::RN RN;
    typedef Types::NN NN;
    typedef Types::R R;

    std::vector<std::shared_ptr<GenericLayer>> d_layers;
    RN  d_inputValues;
    RN  d_targetValues;
    NN  d_layersSize;

public:
    //CREATORS
    Network(RN & inputValues, RN & targetValues, NN & layersSize) ;
    void init(RN & inputValues, RN & targetValues, NN & layersSize);
    void createLayers();
    void createHiddenLayers();
    void createInputLayer();
    void createOutputLayer();

    //MANIPULATORS
    void linkNeurons();
    void updateOutput();
    R computeError();

    //ACCESSORS
    int getNbLayers() const;
    std::vector<std::shared_ptr<GenericLayer>> getLayers() const;
    std::shared_ptr<GenericLayer> getLayer(int j) const;
    std::shared_ptr<GenericLayer> getLastLayer() const;
    std::shared_ptr<GenericNeuron> getNeuron(int j,int i) const;
    R getTargetValue(int i);
    std::shared_ptr<GenericLayer> operator[](int i) const;
};

std::ostream &operator<<(std::ostream &os, const Network &c);

#endif //NN_NETWORK_H
