#ifndef CREATOR_H
#define CREATOR_H

#include "network.h"
#include <vector>
#include <memory>


class Creator{
    public:
        std::vector<Network*> getNetworks(); // getter for _networks
        Network* getNetwork(int index=0); // getter for _networks but only one network
        void deleteNetwork(int index); // delete this network
        void cloneNetwork(Network network, std::vector<float*> inpts, int num, bool mutation=false); // clone network a set amount of time + mutation if needed. also obviously it needs inputs
        void saveNetwork(int index); // delete all except this network
        void createNetwork(std::vector<std::shared_ptr<float>> inputs, int outputs=1); // init with lots of inputs
        void createNetwork(std::shared_ptr<float> input, int outputs=1); // init with one input
        void createNetwork(float &input, int outputs=1); // init with one input variable
        std::vector<float> getOutput(int index=0); // get outputs with index
        std::vector<float> getOutput(Network *network); // get outputs with ptr to network
    private:
        std::vector<std::unique_ptr<Network>> _networks;
        void addNetwork(Network &&network);
};

#endif