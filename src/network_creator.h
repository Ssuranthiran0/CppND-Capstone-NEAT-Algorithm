#ifndef CREATOR_H
#define CREATOR_H

#include "network.h"
#include <vector>


class Creator{
    public:
        std::vector<Network> getNetworks();
        void createNetwork(std::vector<std::shared_ptr<float>> inputs, int outputs=1); // init with lots of inputs
        void createNetwork(std::shared_ptr<float> input, int outputs=1); // init with one input
        void createNetwork(float &input); // init with one input variable
        std::vector<float> getOutputs(int index); // get outputs with index
        std::vector<float> getOutput(Network *network); // get outputs with ptr to network

    private:
        std::vector<Network> _networks;
};

#endif