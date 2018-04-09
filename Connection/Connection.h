//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INPUT_H
#define NN_INPUT_H

#include <memory>
#include <iostream>
class GenericNeuron;

class Connection {
    std::shared_ptr<GenericNeuron> d_from;
    std::shared_ptr<GenericNeuron> d_to;
    double d_weight;
public:

    void setWeight(double d_weight);

public:
    Connection(std::shared_ptr<GenericNeuron> from,std::shared_ptr<GenericNeuron>  to,double weight);
    std::shared_ptr<GenericNeuron> getFrom() const;
    std::shared_ptr<GenericNeuron> getTo() const;
    double getWeight() const;



};
std::ostream& operator<<(std::ostream& os, const Connection& c);

#endif //NN_INPUT_H
