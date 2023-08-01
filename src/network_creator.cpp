#include "network_creator.h"
#include <memory>
#include <new>



// Creator class implementation


std::vector<Network*> Creator::getNetworks(){
    std::vector<Network*> ptrNetList;
    for(auto &node : _networks){
        ptrNetList.emplace_back(node.get());
    }
    return ptrNetList;
}


// erase element (erase takes iterator so not just erase(index)) at index (put comment here for readability)
void Creator::deleteNetwork(int index) { _networks.erase(_networks.begin() + index); } 
Network* Creator::getNetwork(int index){
    return _networks[index].get();
}

void Creator::saveNetwork(int index){ // kinda dumb implementation but thats essentially this whole project
    std::unique_ptr<Network> toBeSaved = std::move(_networks[index]); // get the ptr to be save
    _networks.clear(); // clear the array. hope it doesnt clear the toBeSaved network
    //_networks.emplace_back(std::move(toBeSaved.get())); // put toBeSaved back in
    addNetwork(std::move(*toBeSaved.get()));
}

void Creator::cloneNetwork(Network network, std::vector<float*> inpts, int num, bool mutate){
    for(int i=0; i<num; i++){
        Network clone(network, mutate);
    }
}

void Creator::addNetwork(Network &&network){
    _networks.push_back(std::make_unique<Network>(std::move(network)));
}

void Creator::createNetwork(std::vector<std::shared_ptr<float>> inputs, int outputs){
    Network newNetwork; // create blank network
    for (std::shared_ptr<float> input : inputs){ // iteratively add each input to the blank network
        newNetwork.addInput(input); // add
    }
    newNetwork.addOutput(outputs); // just add
    newNetwork.Initialize(); // populate
    addNetwork(std::move(newNetwork));
}


void Creator::createNetwork(std::shared_ptr<float> input, int outputs){
    Network newNetwork;
    newNetwork.addInput(input); // add input
    for (int i=0; i<outputs; i++){
        newNetwork.addOutput();
    }
    newNetwork.Initialize();
    addNetwork(std::move(newNetwork));
}


void Creator::createNetwork(float &input, int outputs){
    std::shared_ptr<float> in = std::make_shared<float>(input); 
    createNetwork(in, outputs);
}


std::vector<float> Creator::getOutput(int index){ return _networks[index]->getOutputs(); }


std::vector<float> Creator::getOutput(Network *network){ return network->getOutputs(); }