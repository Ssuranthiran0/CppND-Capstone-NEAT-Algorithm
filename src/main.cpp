#include <iostream>
#include <cmath>
#include <memory>
#include "network.h"
#include "network_creator.h"

int main() {

    // Adding inputs to the network
    Creator creator;
    float inputValue1 = 1;
    creator.createNetwork(inputValue1);
    if(creator.getNetworks().size() != 0){ // only do it if creation worked

        // Getting the outputs
        std::vector<float> outputs = creator.getOutput(0); // default to first network stored

        // Printing the outputs
        for (float output : outputs) {
            std::cout << "Output: " << output << std::endl;
        }
    }
    return 0;
}