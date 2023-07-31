#include <iostream>
#include <cmath>
#include <memory>
#include "network.h"

int main() {

    // Adding inputs to the network
    float inputValue1 = 1;
    std::shared_ptr<float> input1 = std::make_shared<float>(inputValue1);
    std::vector<std::shared_ptr<float>> inputs = {input1};

    Network myNetwork;
    for ( std::shared_ptr<float> input : inputs){
        myNetwork.addInput(input);
    }
    myNetwork.Initialize();

    // Getting the outputs
    std::vector<float> outputs = myNetwork.getOutputs();

    // Printing the outputs
    for (float output : outputs) {
        std::cout << "Output: " << output << std::endl;
    }

    return 0;
}