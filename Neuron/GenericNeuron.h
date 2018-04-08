//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_GENERICNEURON_H
#define NN_GENERICNEURON_H

#include <vector>
#include "../Connection/Connection.h"

class GenericNeuron {
    double d_output;
    std::vector<Connection> d_backConnections;
    std::vector<Connection> d_fwdConnections;
public:
    void setInputs(std::vector<Connection> backConnections);
};


#endif //NN_GENERICNEURON_H
