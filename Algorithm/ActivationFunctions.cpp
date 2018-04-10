//
// Created by jbmdu on 09/04/2018.
//

#include "ActivationFunctions.h"
#include "math.h"
#include "../Global/Types.h"

Types::R ActivationFunctions::sigmoid(R x){
    return 1./(1.+exp(-x));
}
