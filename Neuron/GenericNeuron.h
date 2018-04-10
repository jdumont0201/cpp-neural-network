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

    int d_neuronId;
    int d_layerId;
    R d_output;
    std::vector<Connection> d_backConnections;
public:
     std::vector<Connection> &getBackConnections() ;

    void setD_backConnections(const std::vector<Connection> &d_backConnections);

private:
    std::vector<Connection> d_fwdConnections;
protected:
    R activationFunction(R x);

public:
    //CONSTRUCTORS
    GenericNeuron(GenericNeuron* g);
    GenericNeuron();

    //MANIPULATORS
    void setInputs(std::vector<Connection> backConnections);
    void linkNeuronsBackwards(std::shared_ptr<GenericLayer> prevLayer) ;
    virtual R computeOutput();
    virtual R computeError();

    void updateOutput();
    R computeSumOfInputs() ;


    //ACCESSORS
    void setNeuronId(int neuronId);
    int getNeuronId() const;
    void setLayerId(int layerId);
    int getLayerId() const;
    void setOutput(R output);
    R getOutput() const;
};

std::ostream& operator<<(std::ostream& os, const GenericNeuron& c);

#endif //NN_GENERICNEURON_H
