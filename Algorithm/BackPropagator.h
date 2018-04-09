//
// Created by jbmdu on 09/04/2018.
//

#ifndef NN_BACKPROPAGATOR_H
#define NN_BACKPROPAGATOR_H


#include "../Network/Network.h"

class BackPropagator {
    double d_eps;
    int d_maxIterations;
    double d_learningRate=0.1;
    Network &d_N;
    void backPropagate();
    void backPropagateLayer(int j);
public:
    void run();
    BackPropagator(Network &N,double eps,int maxIterations);
};


#endif //NN_BACKPROPAGATOR_H
