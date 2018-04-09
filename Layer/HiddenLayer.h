//
// Created by jbmdu on 08/04/2018.
//

#ifndef NN_INNERLAYER_H
#define NN_INNERLAYER_H


#include "GenericLayer.h"

class HiddenLayer : public GenericLayer{
public:
    explicit HiddenLayer(int layerId,int layerSize);
};


#endif //NN_INNERLAYER_H
