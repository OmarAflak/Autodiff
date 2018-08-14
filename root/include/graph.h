#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "edge.h"

#include <unordered_map>
#include <exception>
#include <vector>

class Node;
class Graph {
    private:
        static Graph* instance;
        std::unordered_map<unsigned long int, Node*> nodes;
        std::unordered_map<unsigned long int, std::vector<Edge*> > edges;

        Graph();
        ~Graph();

        void clear_memory();
        void delete_pointers();
        double gradientRecursive(Node* node);

    public:
        static Graph* getInstance();
        static Graph* getInstanceNoCheck();

        double gradient(const Node& out, const Node& in);
        std::vector<double> gradient(const Node& out, const std::vector<Node>& in);
        std::vector<std::vector<double> > gradient(const Node& out, const std::vector<std::vector<Node> >& in);

        void new_recording();

        bool has(const unsigned long int& uid) const;
        Node* get(const unsigned long int& uid) const;
        Node* create(const Node& node);
        Edge* create(const Edge& edge);

        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

#endif /* end of include guard: GRAPH_H */
