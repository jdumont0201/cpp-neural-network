//
// Created by jbmdu on 09/04/2018.
//

#include "BackPropagator.h"
#include <iostream>

BackPropagator::BackPropagator(Network &N, double eps, int maxIterations) : d_N(N), d_eps(eps),
                                                                            d_maxIterations(maxIterations) {

}

void BackPropagator::backPropagateLayer(int j) {
    for (auto nj : d_N.getLayers()[j]->getNeurons()) {
        for (auto cij : nj->getBackConnections()) {
            //compute terms of derivation dE/dwij
            double yi = cij.getFrom()->getOutput();
            double yj = nj->getOutput();
            double tj = d_N.getTargetValue(j);
            double wij = cij.getWeight();
            double dj, dE_dyj, dEdwij;
            if (j == d_N.getNbLayers() - 1) {//output layer
                dE_dyj = -(tj - yj);
            } else {      //inner layers
                dE_dyj = 0.;
                for (auto nk : d_N.getLayers()[j]->getNeurons()) {
                    dE_dyj +=  wik;
                }
            }
            double dyj_dxj = yj * (1. - yj);
            double dxj_dwij = yi;
            double dE_dwij = dE_dyj * dyj_dxj * dxj_dwij;

            //compute adjusted weight;
            double deltawij = -1. * d_learningRate * dE_dwij;
            double updated_wij =cij.getWeight() + deltawij;
            cij.setWeight(updated_wij);
        }
    }
}
void BackPropagator::backPropagate() {
    //for all layers
    for (int j = d_N.getNbLayers(); j >= 1; --j) {
        backPropagateLayer()
    }
}

void BackPropagator::run() {
    int nbIterations = 0;
    d_N.updateOutput();
    double error = d_N.computeError();
    while (error > d_eps || nbIterations < d_maxIterations) {
        std::cout << "iteration " << nbIterations << "error" << error << std::endl;
        backPropagate();
        nbIterations++;
    }
}
