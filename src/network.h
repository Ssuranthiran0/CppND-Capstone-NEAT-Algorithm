#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <memory>
#include "node.h"

class Network{
    public:
        Network();
        Network(const Network &source);
        void addInput(std::unique_ptr<float> input);
        void calculateNetwork();
        std::vector<float> getOutputs();
    private:
        float _mutationChance = 0.1; // this value divided by score. if it is good, dont change it
        float _initConnectionChance = 0.3; // chance of creating connection at inititialization for each node
        int _hiddenLayers = 3; // number of hidden layers
        int _nodesPerLayer = 2; // number of nodes in each hidden layer
        int _outputs = 1; // output amount
        int _inputs = 1; // input amounts
        std::vector<std::unique_ptr<float>> inputs;
        std::vector<std::vector<Node>> _nodes;
        std::vector<StartNode> _startNodes;
        std::vector<OutputNode> _outputNodes;
};

#endif