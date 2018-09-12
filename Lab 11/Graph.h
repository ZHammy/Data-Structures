#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "List.cpp"

// Instantiated here so it can be a friend of GraphData
template <class T> class Graph;

template <class T> class GraphData {
private:
    T data;
    List<T> adjList;

    friend class Graph<T>;

public:
    // Constructors
    GraphData();
    GraphData(T);
    // ~GraphData();
};

// Graph that uses adjacency list method
// Designed to potentially have holes in list
// Adding new items simply uses first hole found
template <class T> class Graph {
private:
    GraphData<T>** nodes; // Array of pointers to graph data objects
    int size;

public:
    // Constructor / Destructor
    Graph();
    Graph(int);
    ~Graph();

    // Add / Remove
    void addNode(T);
    void addEdge(T, T);
    void removeEdge(T, T);

    // Getters
    bool hasNode(T);
    bool hasEdge(T, T);
    List<T> outEdges(T); // TODO
    List<T> inEdges(T); // TODO
    void breadthFirstSearch(T);
    void depthFirstSearch(T);
    void displayGraph();

    // Error classes
    class GraphNodeDuplicate { public: string msg = "That node already exists!"; };
    class GraphNodeNotFound { public: string msg = "That node does not exist!"; };
    class GraphEdgeNotFound { public: string msg = "That edge does not exist!"; };
};

#endif
