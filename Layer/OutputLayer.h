//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_OUTPUTLAYER_H
#define NN_OUTPUTLAYER_H


#include "GenericLayer.h"
#include "../Global/Declarations.h"

class OutputLayer : public GenericLayer{

public :
explicit OutputLayer(int layerId,RN & targetValues);


};


#endif //NN_OUTPUTLAYER_H
