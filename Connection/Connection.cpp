//
// Created by jbmdu on 08/04/2018.
//

#include "Connection.h"
#include <memory>
#include "../Neuron/GenericNeuron.h"

Connection::Connection(std::shared_ptr<GenericNeuron> from,std::shared_ptr<GenericNeuron>  to,R weight){
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

Connection::R Connection::getWeight() const {
    return d_weight;
}


void Connection::setWeight(R weight) {
    std::cout << "L"<<d_from->getLayerId()<<"-N"<<d_from->getNeuronId()<<" --> L"<<d_to->getLayerId()<<"-N"<<d_to->getNeuronId()<<" Weight: "<<d_weight<<" --> " << weight<<std::endl;
    d_weight = weight;
}

std::ostream& operator<<(std::ostream& os, const Connection& c){
    os << "L"<<c.getFrom()->getLayerId()<<"N"<<c.getFrom()->getLayerId()<<" output:"<<c.getFrom()->getOutput()<<" -> " ;
    os << "L"<<c.getTo()->getLayerId()<<"N"<<c.getTo()->getLayerId()<<" W:"<<
       c.getWeight();
    return os;
}