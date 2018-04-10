//
// Created by jbmdu on 09/04/2018.
//

#include "BackPropagator.h"
#include <iostream>

BackPropagator::BackPropagator(Network &N, double eps, int maxIterations) : d_N(N), d_eps(eps),
                                                                            d_maxIterations(maxIterations) {

}

Types::R BackPropagator::computeUpdatedWeight(int layerId, std::shared_ptr<GenericNeuron> nj, Connection &cij, RNM &d) {
    //1. get data
    R yi = cij.getFrom()->getOutput();
    R yj = nj->getOutput();
    R dj, dE_dyj;

    //2. compute
    R dyj_dxj = yj * (1. - yj);
    if (layerId == d_N.getNbLayers() - 1) {//output layer
        int j = nj->getNeuronId();
        R tj = d_N.getTargetValue(j);
        dE_dyj = (yj - tj);
    } else {                       //inner layers
        dE_dyj = 0.;
        for (auto nk : d_N.getLayer(layerId)->getNeurons()) {
            std::vector<Connection> connections = nk->getBackConnections();
            int k = nj->getNeuronId();
            Connection &ckj = connections[k];
            R wjk = ckj.getWeight();
            dE_dyj += d[layerId + 1][k] * wjk;
        }
    }
    dj = dyj_dxj * dE_dyj;
    d[layerId][nj->getNeuronId()] = dj;

    R dxj_dwij = yi;
    R dE_dwij = dE_dyj * dyj_dxj * dxj_dwij;

    //3. adjust weight
    R deltawij = -1. * d_learningRate * dE_dwij;
    return cij.getWeight() + deltawij;

}

void BackPropagator::backPropagateLayer(int layerId, RNM &d) {
    std::cout << "Propagate Layer " << layerId << std::endl;
    d[layerId] = {};
    d[layerId].resize(d_N.getLayer(layerId)->getSize());
    for (auto nj : d_N.getLayer(layerId)->getNeurons()) {
        std::cout << "Propagate Layer " << layerId << " Neuron " << nj->getNeuronId() << std::endl;
        for (auto cij : nj->getBackConnections()) {
            //compute terms of derivation dE/dwij
            R updated_wij=computeUpdatedWeight(layerId, nj, cij, d);
            cij.setWeight(updated_wij);
        }
    }
}

void BackPropagator::backPropagate() {
    //for all layers
    RNM d;
    d.resize(d_N.getNbLayers());
    for (int j = d_N.getNbLayers() - 1; j >= 1; --j) {
        backPropagateLayer(j, d);
        std::cout << d_N.getConnection(1,1,1)<<std::endl;
    }
}

void BackPropagator::run() {
    int nbIterations = 0;
    d_N.updateOutput();
    R error = d_N.computeError();
    while (error > d_eps && nbIterations < d_maxIterations) {
        std::cout << "Iteration " << nbIterations << "error" << error << std::endl;
        backPropagate();
        std::cout << d_N.getConnection(1,1,1)<<std::endl;
        d_N.updateOutput();
        nbIterations++;
    }
}
