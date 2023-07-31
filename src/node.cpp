#include "node.h"
#include <cmath>
#include <iostream>

// Node Class Implementation
Node::Node(float weight, float bias){
    _weight = weight;
    _bias = bias;
}
float Node::getVal(){
    calculateValues();
    return _value;
}
void Node::clearValues(){
    _values.clear();
}
void Node::addValue(float val) {
    _values.push_back(val);
}

void Node::calculateValues() {
    _value = 0;
    for(float i : _values){
        _value += i;
    }
    _value *= _weight;
    _value += _bias;
    _value = activator(_value);
    giveValues();
}
void Node::giveValues(){
    for(std::shared_ptr<Node> n : _connections){
        n->addValue(_value);
    }
}

std::vector<std::shared_ptr<Node>> Node::getConnections() {
    // Return the connections of the Node
    return _connections;
}

void Node::addConnection(std::shared_ptr<Node> node) {
    // Add a connection to the Node
    _connections.push_back(node);
}

float Node::activator(float val) {
    val = std::tanh(val);
    return val;
}

// StartNode Class Implementation
void StartNode::setValue(float &val){
    value = std::make_unique<float>(val);
}
StartNode::StartNode(float &val){
    value = std::make_unique<float>(val);
}