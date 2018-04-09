//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICNEURON_H
#define NN_GENERICNEURON_H

#include <vector>
#include "../Connection/Connection.h"
#include "../Layer/GenericLayer.h"

class GenericNeuron : public std::enable_shared_from_this<GenericNeuron>{
    int d_neuronId;
    int d_layerId;
    double d_output;
    std::vector<Connection> d_backConnections;
    std::vector<Connection> d_fwdConnections;

public:
    //CONSTRUCTORS
    GenericNeuron(GenericNeuron* g);
    GenericNeuron();

    //MANIPULATORS
    void setInputs(std::vector<Connection> backConnections);
    void linkNeuronsBackwards(std::shared_ptr<GenericLayer> prevLayer) ;
    void computeOutput() ;

    //ACCESSORS
    void setNeuronId(int neuronId);
    int getNeuronId();
    void setLayerId(int layerId);
    int getLayerId();
    void setOutput(double output);
    int getOutput();
};


#endif //NN_GENERICNEURON_H
