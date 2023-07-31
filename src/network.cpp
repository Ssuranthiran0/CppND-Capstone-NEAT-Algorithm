#include "network.h" // Header
#include "node.h" // Node, StartNode, OutputNode
#include <memory> // smart ptr
#include <iostream> // std::cout
#include <random> // random generation
#include <vector> // std::vector 

void Network::Initialize(){
    for(int i=0; i<_inputs; i++){
        _startNodes.emplace_back(std::move(inputs[i]), i); // emplace back calls the constructor of vector's type
    }
    for(int i=0; i<_hiddenLayers; i++){
        std::vector<Node> layer;
        for(int j=0; j<_nodesPerLayer; j++){
            layer.emplace_back(_defaultWeight, _defaultBias, i+1, j);
        }
        _nodes.emplace_back(layer);
    }
    for(int i=0; i<_outputs; i++){
        _outputNodes.emplace_back(i);
    }
}
Network::Network(){}
Network::Network(std::vector<float>& inpts){

}
Network::~Network(){
    // Smart Ptr Overrides
}


template <typename T, typename P> 
void connect(std::vector<T> &first, std::vector<P> &second){
    for(T &src : first){
        for(P &target : second){
            src.addConnection(std::make_shared<Node>(target));
        }
    }
}

void Network::addInput(std::shared_ptr<float> input){
    inputs.emplace_back(std::move(input));
}
void Network::printStructure(){

}
void Network::addConnections(std::vector<StartNode> &inputs, std::vector<std::vector<Node>> &nodes, std::vector<OutputNode> &outputs){}
void Network::calculateNetwork(){

    // Clear any previous Values
    for (std::vector<Node>& layer : _nodes) {
        for (Node& node : layer) {
            node.clearValues();
        }
    }

    for (OutputNode &node : _outputNodes) {
        node.clearValues();
    } 

    for (StartNode& i : _startNodes) { // loop thru all start nodes
        i.giveValues(); // make current start node give value to all connected
    }
    // Calculate values for hidden layers
    for (std::vector<Node>& layer : _nodes){
        for (Node& node : layer){ // for each node in the layer
            node.giveValues(); // make it give values to all connections
        }
    }
}
std::vector<float> Network::getOutputs(){
    std::vector<float> outputs;
    outputs.reserve(_outputs);
    for (int i = 0; i < _outputs; i++) {
        outputs.push_back(_outputNodes[i].getVal());
    }
    return outputs;
}