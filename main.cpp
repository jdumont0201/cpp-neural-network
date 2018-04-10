#include <iostream>
#include <vector>

#include "Global/Global.h"
#include "Network/Network.h"
#include <iostream>
#include "Global/Types.h"
#include "Algorithm/BackPropagator.h"
#include "Global/Types.h"
int main() {
    std::cout << "Neural network v0.1"<<std::endl;
    Global g;

    //network parameters
    Types::RN inputValues={4,5};
    Types::RN targetValues={4,5};
    Types::NN layersSize={2,3,2};

    Network N(inputValues,targetValues,layersSize);
    std::cout << N <<std::endl;
    std::cout<<"error"<<N.computeError()<<std::endl;
    N.updateOutput();
    std::cout << N <<std::endl;
    std::cout<<"error"<<N.computeError()<<std::endl;

    BackPropagator B(N,0.1,100);
    B.run();
    return 0;
}