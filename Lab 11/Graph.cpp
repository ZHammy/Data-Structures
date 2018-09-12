#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include "Graph.h"

using namespace std;

const int ARRAY_SIZE_DEFAULT = 20;

// ------- UTILITY FUNCTIONS -------
template<class T> bool isInVector(vector<T> vectorIn, T searchVal) {
    // Function used from the algorithm library
    // .end() looks one past list, and find returns .end() if item is not found
    return find(vectorIn.begin(), vectorIn.end(), searchVal) != vectorIn.end();
}

template<class T> bool isInQueue(queue<T> queueIn, T searchVal) {
    T thisVal; // Temp comparison variable

    // Cycle through each item in queue, return true if item found
    while (!queueIn.empty()) {
        thisVal = queueIn.front();
        if (thisVal == searchVal) { return true; }
        queueIn.pop();
    }

    // If we reach this point, the val is not in the queue
    return false;
}

// ------- GRAPH DATA -------
template <class T> GraphData<T>::GraphData() {
    // TODO: Anything to initialize here?
}

template <class T> GraphData<T>::GraphData(T inVal) {
    data = inVal;
}

// ------- GRAPH CLASS -------

// Constructors / Deconstructor
template <class T> Graph<T>::Graph() {
    size = ARRAY_SIZE_DEFAULT;
    nodes = new GraphData<T>*[size];

    // Initialize all the nodes values to null pointers
    for (int i = 0; i < size; i++) {
        nodes[i] = nullptr;
    }
}

template <class T> Graph<T>::Graph(int sizeIn) {
    size = sizeIn;
    nodes = new GraphData<T>*[size];

    // Initialize all the nodes values to null pointers
    for (int i = 0; i < size; i++) {
        nodes[i] = nullptr;
    }
}

template <class T> Graph<T>::~Graph() {
    // Ensure all values are deleted on deconstruct
    for (int i = 0; i < size; i++) {
        delete nodes[i];
    }

    delete nodes;
}

// Add / Remove
template <class T> void Graph<T>::addNode(T inVal) {
    if (hasNode(inVal)) { GraphNodeDuplicate e; throw e; }
    else {
        GraphData<T>* newVal = new GraphData<T>(inVal);

        for (int i = 0; i < size; i++) {
            if (nodes[i] == nullptr) {
                nodes[i] = newVal;
                return;
            }
        }

        // Should never reach this point
        cout << "Graph is full!" << endl;
        delete newVal;
    }
}

template <class T> void Graph<T>::addEdge(T nodeVal, T edgeVal) {
    if (!hasNode(edgeVal)) {
        GraphNodeNotFound e;
        e.msg = "Edge must be a node first!";
        throw e;
    }

    else {
        // Cycle through and find the given node value we will add to
        for (int i = 0; i < size; i++) {
            if (nodes[i] != nullptr && nodes[i]->data == nodeVal) {
                nodes[i]->adjList.addItem(new int(edgeVal));
                return;
            }
        }

        cout << "Given node value does not exist!" << endl;
    }
}

template <class T> void Graph<T>::removeEdge(T nodeVal, T edgeVal) {
    if (!hasNode(nodeVal)) { GraphNodeNotFound e; throw e; }

    // Cycle through and find the given node val we will remove from
    for (int i = 0; i < size; i++) {
        if (nodes[i] != nullptr && nodes[i]->data == nodeVal) {
            T* edgePointer = new T(edgeVal); // Pointer for list comparison

            try {
                // Remove the given edge value then delete it
                // Done in this way due to how the List is defined
                T* temp = nodes[i]->adjList.getItem(edgePointer);
                delete temp;

            } catch (typename List<T>::ListItemNotFound) {
                delete edgePointer;

                GraphEdgeNotFound e;
                e.msg = "That edge does not exist!";
                throw e;
            }

            delete edgePointer;
            return;
        }
    }
}

// Getters
template <class T> bool Graph<T>::hasNode(T nodeVal) {
    // Cycle through and see if we can find the given node value
    for (int i = 0; i < size; i++) {
        if (nodes[i] != nullptr && nodes[i]->data == nodeVal) {
            return true;
        }
    }

    // If we ever reach this point, then the node does not exist
    return false;
}

template <class T> bool Graph<T>::hasEdge(T nodeVal, T edgeVal) {
    // Cycle through and see if we can find the given node value
    for (int i = 0; i < size; i++) {
        if (nodes[i] != nullptr && nodes[i]->data == nodeVal) {
            // Check if the given value is in the list
            // Made a pointer to accomodate List definition
            T* edgePointer = new T(edgeVal);
            bool retVal = nodes[i]->adjList.isInList(edgePointer);

            // Delete temp pointer and return bool
            delete edgePointer;
            return retVal;
        }
    }

    // If we reach this point, then the given node does not exist
    return false;
}
template <class T> List<T> Graph<T>::inEdges(T inVal) {
    if (!hasNode(inVal)) { GraphNodeNotFound e; throw e; }

    List<T> retList;
    T* temp= new T(inVal);
    for(int i=0;i<size;i++){
        if(nodes[i] != nullptr && nodes[i]->adjList.isInList(temp)){
            T* temp=new T(nodes[i]->data);
            retList.addItem(temp);
        }
    }
	return retList;

}

template <class T> List<T> Graph<T>::outEdges(T inVal) {
    if (!hasNode(inVal)) { GraphNodeNotFound e; throw e; }

    for(int i=0;i<size;i++){
        if (nodes[i] != nullptr && inVal==nodes[i]->data){
            return nodes[i]->adjList;
        }
    }
}

template <class T> void Graph<T>::displayGraph() {
    bool empty = true; // Track if the graph is empty

    // Cycle through all nodes and display
    for (int i = 0; i < size; i++) {
        if (nodes[i] != nullptr) {
            empty = false;

            cout << "Index: " << i << endl;
            cout << "Data:  " << nodes[i]->data << endl;
            cout << "Adjacent values:" << endl;

            // Reset the seeNext watch
            nodes[i]->adjList.reset();

            // Get the first value in the linked list
            Node<T>* tempNode = nodes[i]->adjList.seeNext();

            // Clarify if there are no adjacent values
            if (tempNode == nullptr) {
                cout << "None" << endl;
            } else {
                // Cycle through and print each adjacency list val
                while (tempNode != nullptr) {
                    cout << tempNode->data << endl;
                    tempNode = nodes[i]->adjList.seeNext();
                }
            }

            nodes[i]->adjList.reset(); // Reset the seeNext watch again
            cout << endl; // Print end line for readability
        }
    }

    if (empty) {
        cout << "Graph is empty!" << endl;
    }
}

template <class T> void Graph<T>::breadthFirstSearch(T inVal) {
    // Error out if the given value is not an existing node
    if (!hasNode(inVal)) { GraphNodeNotFound e; throw e; }

    // Make a queue to store nodes that need visiting
    queue<T> myQueue;

    // Keep track of nodes that have been visited
    // Vector for easy appending
    vector<T> visited;

    int index;
    myQueue.push(inVal);
    T curNode;
    while(!myQueue.empty()){
        // Take the oldest node out and display
        // STD queue.pop() returns void, so requires some extra work
        curNode = myQueue.front();
        myQueue.pop();
        cout<<curNode<<endl;

        visited.push_back(curNode); // Mark this as visited

        // Find the current node index
        for(int i=0;i<size;i++){
            if (nodes[i] != nullptr && curNode==nodes[i]->data){
                index=i;
                break;
            }
        }

        // Find all of this node's children and add to queue
        Node<T>* tempNode = nodes[index]->adjList.seeNext();
        while(tempNode != nullptr) {
            // Search for the index of this node
            // In theory, should always be found unless there is was an edge
            // added that is not a node first
            int tempIndex = 0;
            for (int i = 0; i < size; i++) {
                if (nodes[i] != nullptr && nodes[i]->data == tempNode->data) {
                    tempIndex = i;
                    break;
                }
            }

            // Push the next value to the queue if it has not been visited
            // and is not already in the queue
            if (!isInVector<T>(visited, tempNode->data) && !isInQueue<T>(myQueue, tempNode->data)) {
                myQueue.push(tempNode->data);
            }

            tempNode = nodes[index]->adjList.seeNext();
        }

        nodes[index]->adjList.reset(); // Reset look variable after searching
    }
}


template <class T> void Graph<T>::depthFirstSearch(T inVal) {
    // Error out if the given value is not an existing node
    if (!hasNode(inVal)) { GraphNodeNotFound e; throw e; }

    // Make a vector to store nodes that need visiting
    vector<T> myVector;

    // Keep track of nodes that have been visited
    // Vector for easy appending
    vector<T> visited;

    int index;
    myVector.push_back(inVal);
    T curNode;
    bool foundANewNode=true;
    int nodesFound=0;
    while(!myVector.empty()){
        // Take the oldest node out and display
        // STD queue.pop() returns void, so requires some extra work
        curNode = myVector.back();
        if(!foundANewNode){
            // if(nodesFound==size-1){
            //     visited.push_back(myVector.back());
            // }
            myVector.pop_back();
        }
        else{
            visited.push_back(curNode);
        }
        foundANewNode=false;

         // Mark this as visited

        // Find the current node index
        for(int i=0;i<size;i++){
            if (nodes[i] != nullptr && curNode==nodes[i]->data){
                index=i;
                break;
            }
        }

        // Find all of this node's children and add to queue
        Node<T>* tempNode = nodes[index]->adjList.seeNext();
        while(tempNode != nullptr) {
            // Search for the index of this node
            // In theory, should always be found unless there is was an edge
            // added that is not a node first
            int tempIndex = 0;
            for (int i = 0; i < size; i++) {
                if (nodes[i] != nullptr && nodes[i]->data == tempNode->data) {
                    tempIndex = i;
                    break;
                }
            }

            // Push the next value to the queue if it has not been visited
            // and is not already in the queue
            if (!isInVector<T>(visited, tempNode->data) && !isInVector<T>(myVector, tempNode->data)) {
                foundANewNode=true;
                nodesFound++;
                myVector.push_back(tempNode->data);
                nodes[index]->adjList.reset();
                break;
            }

            tempNode = nodes[index]->adjList.seeNext();
        }

         // Reset look variable after searching
    }

    for(int i=0;i<visited.size();i++){
        cout<<visited.at(i)<<endl;
    }
}
    // // Error out if the given value is not an existing node
    // if (!hasNode(inVal)) { GraphNodeNotFound e; throw e; }
    //
    // //make a queue to store visited nodes in order
    // queue<T> myVector;
    // //make a vector to help parsing our nodes
    // vector<T> myVector;
    // //Keeps track of if a node is visited or not
    // bool *isVisited=new bool[size];
    // int index;
    // myQueue.push(inVal);
    // myVector.push_back(inVal);
    // T curNode;
    // int nodesVisited=1;
    // bool foundANewNode=true;
    // while(nodesVisited<size){
    //     //Use the most recently added item as the current node
    //     //If an item wasn't found last iteration however, remove the last item
    //     if(!foundANewNode){
    //         myVector.pop_back();
    //     }
    //     curNode=myVector.back();
    //     foundANewNode=false;
    //
    //     for(int i=0;i<size;i++){
    //         if (curNode==nodes[i]->data){
    //             isVisited[i]=true;
    //             index=i;
    //             break;
    //         }
    //     }
    //     List<T> *tempAdjList;
    //     *tempAdjList = nodes[index]->adjList;
    //     for(int i=0;i<size;i++){
    //         for(int j=0;j<tempAdjList->size();j++){
    //             try{
    //                 if(!isVisited[i]){
    //                     myQueue.push(*(tempAdjList->getItem(nodes[i])));
    //                     myVector.push_back(*(tempAdjList->getItem(nodes[i])));
    //                     isVisited[i]=true;
    //                     foundANewNode=true;
    //                     break;
    //                 }
    //             }
    //             catch(...){}
    //         }
    //         //If the break inside the try catch triggers, it will go here
    //         //This is a clevel way of breaking out of the other for loop
    //         if(nodesVisited<myQueue.size()){
    //             nodesVisited++;
    //             break;
    //         }
    //     }
    // }
    // for(int i=0;i<myQueue.size();i++){
    //     cout<<myQueue.front()<<endl;
    //     myQueue.pop();
    // }
// }

#endif
