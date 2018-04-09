#include <iostream>
#include <vector>

#include "Global/Global.h"
#include "Network/Network.h"
#include <iostream>
#include "Global/Declarations.h"
#include "Algorithm/BackPropagator.h"

int main() {
    std::cout << "Neural network v0.1"<<std::endl;
    Global g;

    //network parameters
    RN inputValues={2,4,5};
    RN targetValues={4,5};
    NN layersSize={3,5,5,2};

    Network N(inputValues,targetValues,layersSize);
    std::cout << N <<std::endl;
    std::cout<<"error"<<N.computeError()<<std::endl;
    N.updateOutput();
    std::cout << N <<std::endl;
    std::cout<<"error"<<N.computeError()<<std::endl;

    BackPropagator B(N,0.1,1000);
    B.run();
    return 0;
}