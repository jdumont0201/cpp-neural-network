//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICLAYER_H
#define NN_GENERICLAYER_H

#include <vector>
#include <memory>
#include "../Global/Types.h"

class GenericNeuron;


class GenericLayer {
    typedef Types::R R;
    typedef typename Types::RN RN;

    const int d_layerId;
    R d_bias;
protected :
    std::vector<std::shared_ptr<GenericNeuron>> d_neurons;
public:
    //CONSTRUCTORS
    GenericLayer(int layerId);

    //MANIPULATORS
    void linkNeuronsBackwards(std::shared_ptr<GenericLayer> &prevLayer);
    void setLayerId(int layerId);
    void updateOutput() ;
    virtual R computeError(); //overriden by OutputLayer

    //ACCESSORS
    std::vector<std::shared_ptr<GenericNeuron>> getNeurons() const;
    int getLayerId();
    int getSize() const;
    std::shared_ptr<GenericNeuron> getNeuron(int i) const;
};
std::ostream &operator<<(std::ostream &os, const GenericLayer &c);

#endif //NN_GENERICLAYER_H
