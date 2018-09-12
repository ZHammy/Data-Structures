#include <iostream>
#include "Graph.cpp"

using namespace std;

int main () {
    Graph<int> hello;
    hello.addNode(3);
    hello.addNode(5);
    hello.addNode(7);
    hello.addNode(9);
    hello.addNode(20);

    // Everything is just in a straight line
    hello.addEdge(3,5);
    hello.addEdge(5,3);
    hello.addEdge(5,7);
    hello.addEdge(7,5);
    hello.addEdge(7,9);
    hello.addEdge(9,7);
    hello.addEdge(3,9);
    hello.addEdge(3,20);
    hello.addEdge(20,5);

    // Should display "3 5 9 20 7"
    cout<<"Breadth"<<endl;
    hello.breadthFirstSearch(3);
    cout<<endl<<"Depth"<<endl;
    hello.depthFirstSearch(3);

    return 0;
}
