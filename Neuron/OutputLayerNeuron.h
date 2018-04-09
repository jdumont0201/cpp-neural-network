//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_OUTPUTLAYERNEURON_H
#define NN_OUTPUTLAYERNEURON_H


#include "GenericNeuron.h"

class OutputLayerNeuron : public GenericNeuron {
    double d_target;
protected:
    void setTarget(double target);
public:
    OutputLayerNeuron(int layerId,int neuronId,double target);
};


#endif //NN_OUTPUTLAYERNEURON_H
