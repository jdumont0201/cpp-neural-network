//
// Created by jbmdu on 09/04/2018.
//

#include "ActivationFunctions.h"
#include "math.h"
 double ActivationFunctions::sigmoid(double x){
    return 1./(1.+exp(-x));
}

double ActivationFunctions::derivative_sigmoid(double x) {
    double s=sigmoid(x);
    return s*(1.-s);
}
