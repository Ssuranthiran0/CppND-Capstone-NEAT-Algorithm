#include <iostream>
#include <cmath>
#include "network.h"

int main() {
    Network myNetwork;

    // Adding inputs to the network
    float inputValue1 = 1;
    std::shared_ptr<float> input1 = std::make_shared<float>(inputValue1);
    myNetwork.addInput(std::move(input1));

    // Calculating the network's outputs
    myNetwork.Initialize();
    myNetwork.calculateNetwork();

    // Getting the outputs
    std::vector<float> outputs = myNetwork.getOutputs();

    // Printing the outputs
    for (float output : outputs) {
        std::cout << "Output: " << output << std::endl;
    }

    return 0;
}