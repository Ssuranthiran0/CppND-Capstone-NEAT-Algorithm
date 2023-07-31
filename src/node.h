#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>

class Node {
    public:
        Node(float weight=1, float bias=0);
        void addValue(float val); // add a value to the "queue" of values to be calculated
        void calculateValues(); // calculate everything
        void giveValues();
        void clearValues();
        float getVal();
        std::vector<std::shared_ptr<Node>> getConnections();
        void addConnection(std::shared_ptr<Node> node);
        friend class Network;
        std::vector<float> _values;
    private: 
        std::vector<std::shared_ptr<Node>> _connections; // shared_ptr to allow copying 
    protected:
        // take linear value (after calculation from sum(inputs) * weight, and introduce some nonlinearity)
        float _weight{1.0}; // multiply input by weight
        float _value;
        float activator(float val); 
        float _bias; // plain addition
};
class StartNode : public Node{ 
    public:
        StartNode(float &val);
        std::shared_ptr<float> value;
        void setValue(float &val);
};
class OutputNode : public Node {
};

#endif // NODE_H