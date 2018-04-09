//
// Created by jbmdu on 08/04/2018.
//

#include "Connection.h"
#include <memory>

Connection::Connection(std::shared_ptr<GenericNeuron> from,std::shared_ptr<GenericNeuron>  to,double weight){
    d_from=from;
    d_to=to;
    d_weight=weight;
}
std::shared_ptr<GenericNeuron> Connection::getFrom(){
    return d_from;
}
std::shared_ptr<GenericNeuron> Connection::getTo(){
    return d_to;
}

double Connection::getWeight() {
    return d_weight;
}