//
// Created by jbmdu on 09/04/2018.
//

#ifndef NN_BACKPROPAGATOR_H
#define NN_BACKPROPAGATOR_H


#include "../Network/Network.h"

class BackPropagator {
    typedef Types::R R;
    typedef Types::RN RN;
    typedef Types::RNM RNM;
    double d_eps;
    int d_maxIterations;
    double d_learningRate=1;
    Network &d_N;
    void backPropagate();
    void backPropagateLayer(int layerId, RNM & d);
public:
    //CONSTRUCTORS
    BackPropagator(Network &N,double eps,int maxIterations);

    //MANIPULATORS
    void run();
    R computeUpdatedWeight(int layerId,std::shared_ptr<GenericNeuron> nj,Connection & cij,RNM & d);

};


#endif //NN_BACKPROPAGATOR_H
