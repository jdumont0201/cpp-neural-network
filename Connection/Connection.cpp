//
// Created by jbmdu on 08/04/2018.
//

#include "Connection.h"
#include <memory>
#include "../Neuron/GenericNeuron.h"

Connection::Connection(std::shared_ptr<GenericNeuron> from,std::shared_ptr<GenericNeuron>  to,double weight){
    d_from=from;
    d_to=to;
    d_weight=weight;
}
std::shared_ptr<GenericNeuron> Connection::getFrom() const {
    return d_from;
}
std::shared_ptr<GenericNeuron> Connection::getTo() const{
    return d_to;
}

double Connection::getWeight() const {
    return d_weight;
}


void Connection::setWeight(double d_weight) {
    Connection::d_weight = d_weight;
}

std::ostream& operator<<(std::ostream& os, const Connection& c){
    os << "L"<<c.getFrom()->getLayerId()<<"N"<<c.getFrom()->getLayerId()<<" output:"<<c.getFrom()->getOutput()<<" -> " ;
    os << "L"<<c.getTo()->getLayerId()<<"N"<<c.getTo()->getLayerId()<<" W:"<<
       c.getWeight();
    return os;
}