//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUT_H
#define NN_INPUT_H

#include <memory>
#include <iostream>
#include "../Global/Types.h"
class GenericNeuron;

class Connection {
    typedef Types::R R;
    const std::shared_ptr<GenericNeuron> d_from;
    const std::shared_ptr<GenericNeuron> d_to;
    R d_weight;
public:
    //CONSTRUCTORS
    Connection(std::shared_ptr<GenericNeuron> from,std::shared_ptr<GenericNeuron>  to,R weight);

    //MANIPULATORS
    void setWeight(R d_weight);

    //ACCESSORS
    std::shared_ptr<GenericNeuron> getFrom() const;
    std::shared_ptr<GenericNeuron> getTo() const;
    R getWeight() const;
};
std::ostream& operator<<(std::ostream& os, const Connection& c);

#endif //NN_INPUT_H
