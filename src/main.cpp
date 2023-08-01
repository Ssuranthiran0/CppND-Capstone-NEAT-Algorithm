#include <iostream>
#include <cmath>
#include <memory>
#include "network.h"
#include "network_creator.h"

int main() {

    // Adding inputs to the network
    Creator creator;
    std::vector<float> inputValues = {3,5,6,8,20};
    creator.createNetworks(inputValues);
    if(creator.getNetworks().size() != 0){ // only do it if creation worked

        // Getting the outputs
        std::vector<std::vector<float>> outputs = creator.getOutputs();

        // Printing the outputs
        for (int i = 0; i < outputs.size(); i++) {
            for(int j = 0; j < outputs[i].size(); j++)  {
                creator.getNetwork(i)->printStructure();
                std::cout << "Output: " << outputs[i][j] << std::endl;
            }
        }
    }
    return 0;
}