#include <iostream>
#include <vector>

#include "Global/Global.h"
#include "Network/Network.h"


int main() {
    Global g;

    //network parameters
    std::vector<double> inputValues={2,4,5};
    std::vector<double> targetValues={4,5};
    std::vector<int> layersSize={3,10,2};

    Network N(inputValues,targetValues,layersSize);
    return 0;
}