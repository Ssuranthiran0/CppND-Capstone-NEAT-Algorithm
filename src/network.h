#ifndef NETWORK_H // if not defined
#define NETWORK_H // define

#include <vector>
#include <memory>
#include "node.h"

class Network{
    public:
        Network(); // regular constructor | create blank network
        Network(std::vector<float> &inpts); // regular constructor | create network from inputs

        //// Ro5
        ~Network(); // Destructor
        Network(const Network &source, bool mutate); // copy constructor | copy existing network + mutate
        Network& operator=(const Network &source); // copy assignment op
        Network(Network &&source); // move constructor
        Network& operator=(Network &&source); // move assignment op
    
        //// EOF Ro5

        void Initialize();
        void addInput(std::shared_ptr<float> input); // add an input variable
        template <typename T, typename P> void connect(std::vector<T> &first, std::vector<P> &second); // connect all elements of first to second
        void addConnections(std::vector<StartNode> &inputs, std::vector<std::vector<Node>> &nodes, std::vector<OutputNode> &outputs); // add connections
        void calculateNetwork(); // self explanatory
        void printStructure(); // print whole network structure
        std::vector<float> getOutputs(); // get the final outputs
    private:
        float _mutationChance = 0.1; // this value divided by score. if it is good, dont change it
        float _defaultWeight = 1; // starting weight
        float _defaultBias = 0; // starting bias
        float _initConnectionChance = 0.3; // chance of creating connection at inititialization for each node
        int _hiddenLayers = 2; // number of hidden layers
        int _nodesPerLayer = 3; // number of nodes in each hidden layer
        int _outputs = 1; // output amount
        int _inputs = 1; // input amounts
        std::vector<std::shared_ptr<float>> inputs;
        std::vector<std::vector<Node>> _nodes;
        std::vector<StartNode> _startNodes;
        std::vector<OutputNode> _outputNodes;
};

#endif // end the if statement