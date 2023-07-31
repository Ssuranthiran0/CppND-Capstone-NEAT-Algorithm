#include "network_creator.h"
#include <memory>

std::vector<Network> Creator::getNetworks(){
    return _networks;
}

void Creator::createNetwork(std::vector<std::shared_ptr<float>> inputs, int outputs){
    Network newNetwork;
    for ( std::shared_ptr<float> input : inputs){
        newNetwork.addInput(input);
    }
    newNetwork.Initialize();
    _networks.emplace_back(newNetwork);
}

void Creator::createNetwork(std::shared_ptr<float> input, int outputs){
    
}

void Creator::createNetwork(float &input){
    std::shared_ptr<float> in(&input);
}

std::vector<float> Creator::getOutputs(int index){ return _networks[index].getOutputs(); }

std::vector<float> Creator::getOutput(Network *network){
    return {};
}