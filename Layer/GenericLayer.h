//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICLAYER_H
#define NN_GENERICLAYER_H

#include <vector>
#include <memory>

class GenericNeuron;


class GenericLayer {
    int d_layerId;
protected :
    std::vector<std::shared_ptr<GenericNeuron>> d_neurons;
public:
    std::vector<std::shared_ptr<GenericNeuron>> getNeurons();
    void linkNeuronsBackwards(std::shared_ptr<GenericLayer> &prevLayer);
    void setLayerId(int layerId);
    int getLayerId();
    void computeOutput() ;
};


#endif //NN_GENERICLAYER_H
