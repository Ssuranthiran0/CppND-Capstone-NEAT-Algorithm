#include "network.h"
#include <memory>
#include <vector>

Network::Network(){
    for(int i=0; i<_inputs; i++){
        _startNodes.emplace_back(inputs[i]); // emplace back calls the constructor of vector's type
    }
    for(int i=0; i<_hiddenLayers; i++){
        std::vector<Node> layer;
        for(int j=0; j<_nodesPerLayer; j++){
            layer.emplace_back();
        }
        _nodes.emplace_back(layer);
    }
    for(int i=0; i<_outputs; i++){
        _outputNodes.emplace_back();
    }
}
void Network::addInput(std::unique_ptr<float> input){
    inputs.emplace_back(std::move(input));
}
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
    for (int i = 0; i < _inputs; i++) {
        _startNodes[i].giveValues();
        for (Node& node : _nodes[0]) {
            node.addValue(_startNodes[i].getVal());
        }
    }

    // Calculate values for hidden layers
    for (int layerIndex = 0; layerIndex < _hiddenLayers - 1; layerIndex++) {
        for (Node& node : _nodes[layerIndex]) {
            node.calculateValues();
            const float nodeValue = node.getVal();
            const auto& connections = node.getConnections();
            for (const std::shared_ptr<Node>& connectedNode : connections) {
                connectedNode->addValue(nodeValue);
            }
        }
    }

    // Calculate values for the last hidden layer
    for (Node& node : _nodes[_hiddenLayers - 1]) {
        node.calculateValues();
        const float nodeValue = node.getVal();
        const std::vector<std::shared_ptr<Node>>& connections = node.getConnections();
        for (const std::shared_ptr<Node>& connectedNode : connections) {
            connectedNode->addValue(nodeValue);
        }
    }

    // Calculate values for output nodes
    for (int i = 0; i < _outputs; i++) {
        _outputNodes[i].calculateValues();
    }
}
std::vector<float> Network::getOutputs(){
    std::vector<float> outputs;
    outputs.reserve(_outputs);
    for (int i = 0; i < _outputs; i++) {
        outputs.push_back(_outputNodes[i].getVal());
    }
    return outputs;}