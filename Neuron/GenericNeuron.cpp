//
// Created by jbmdu on 08/04/2018.
//

#include "GenericNeuron.h"

void GenericNeuron::setInputs(std::vector<Connection> backConnections) {
    d_backConnections = backConnections;
}