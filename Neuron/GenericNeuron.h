//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICNEURON_H
#define NN_GENERICNEURON_H

#include <vector>
#include "../Connection/Connection.h"
#include "../Layer/GenericLayer.h"
#include "../Global/Types.h"

class GenericNeuron : public std::enable_shared_from_this<GenericNeuron>{
    typedef Types::R R;

    const int d_neuronId;
    const int d_layerId;
    R d_output;
    std::vector<Connection> d_backConnections;
    std::vector<Connection> d_fwdConnections;
protected:
    R activationFunction(R x);

public:
    //CONSTRUCTORS
    GenericNeuron(int layerId,int neuronId);

    //MANIPULATORS
    void linkNeuronsBackwards(std::shared_ptr<GenericLayer> prevLayer) ;
    virtual R computeOutput();
    virtual R computeError();

    void updateOutput();
    R computeSumOfInputs() ;


    //ACCESSORS
    std::vector<Connection> &getBackConnections() ;
    Connection &getBackConnection(int i) ;
    int getNeuronId() const;
    int getLayerId() const;
    void setOutput(R output);
    R getOutput() const;
};

std::ostream& operator<<(std::ostream& os, const GenericNeuron& c);

#endif //NN_GENERICNEURON_H
