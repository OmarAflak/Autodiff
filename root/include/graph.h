#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "edge.h"

#include <map>

class Node;
class Graph {
    private:
        std::map<std::string, Node*> nodes;
        std::map<std::string, std::vector<Edge*> > edges;

        double gradientRecursive(Node* node);

    public:
        Graph();
        Graph(std::initializer_list<Node*> list);
        ~Graph();

        double gradient(const Node& out, const Node& in);

        bool has(const std::string& uid) const;
        Node* get(const std::string& uid) const;
        std::string create(const Node& node);
        void add(const Edge& edge);

        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

#endif /* end of include guard: GRAPH_H */
