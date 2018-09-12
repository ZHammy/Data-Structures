#include <iostream>
#include "Graph.cpp"
#include "limits.h"

using namespace std;

int checkInt(string, int = -INT_MAX, int = INT_MAX); // Prompt for ints within a range of two numbers

int main () {
    Graph<int> ourGraph;
    int choice;
    //Hardcoding in the nodes from figure 1
    ourGraph.addNode(0);
    ourGraph.addNode(1);
    ourGraph.addNode(2);
    ourGraph.addNode(3);
    ourGraph.addNode(4);
    ourGraph.addNode(5);
    ourGraph.addNode(6);
    ourGraph.addNode(7);
    ourGraph.addNode(8);
    ourGraph.addNode(9);
    //Add all the edges from figure 1
    ourGraph.addEdge(9,5);
    ourGraph.addEdge(9,4);
    ourGraph.addEdge(9,8);
    ourGraph.addEdge(5,9);
    ourGraph.addEdge(5,0);
    ourGraph.addEdge(5,6);
    ourGraph.addEdge(6,5);
    ourGraph.addEdge(6,1);
    ourGraph.addEdge(6,7);
    ourGraph.addEdge(7,6);
    ourGraph.addEdge(7,8);
    ourGraph.addEdge(7,2);
    ourGraph.addEdge(8,7);
    ourGraph.addEdge(8,3);
    ourGraph.addEdge(8,9);

    ourGraph.addEdge(4,9);
    ourGraph.addEdge(4,1);
    ourGraph.addEdge(4,2);
    ourGraph.addEdge(0,5);
    ourGraph.addEdge(0,3);
    ourGraph.addEdge(0,2);
    ourGraph.addEdge(1,6);
    ourGraph.addEdge(1,3);
    ourGraph.addEdge(1,4);
    ourGraph.addEdge(2,7);
    ourGraph.addEdge(2,4);
    ourGraph.addEdge(2,0);
    ourGraph.addEdge(3,8);
    ourGraph.addEdge(3,1);
    ourGraph.addEdge(3,0);


    while (true) {
        // Menu output / input
        cout << "What would you like to do to your graph?" << endl
             << "1: Add a node to graph" << endl
             << "2: Add an edge to graph" << endl
             << "3: Remove an edge from graph" << endl
             << "4: Find an edge in the graph" << endl
             << "5: Find the out edges of a node" << endl
             << "6: Find the in edges of a node" << endl
             << "7: Display the graph as adjacency lists" << endl
             << "8: Display a depth first search path" << endl
             << "9: Display a breadth first search path" << endl
             << "10: Quit" << endl;
        choice = checkInt("Enter your selection:  ",1,10);

        // Check first if program will be exites
        if (choice == 10) { break; }

        try {
            // Remaining menu options
            switch (choice) {
                // Add node
                case 1:
                    {
                        int inVal;
                        inVal = checkInt("What value would you like to insert?  ");
                        ourGraph.addNode(inVal);
                    }
                    break;
                // Add edge
                case 2:
                    {
                        int inNode; int inEdge;
                        inNode = checkInt("What node would you like to add an edge to?  ");
                        inEdge = checkInt("What edge would you like to add to your node?  ");
                        ourGraph.addEdge(inNode, inEdge);
                    }
                    break;
                // Remove edge
                case 3:
                    {
                        int inNode; int inEdge;
                        inNode = checkInt("What node would you like to remove an edge from?  ");
                        inEdge = checkInt("What edge would you like to remove from your node?  ");
                        ourGraph.removeEdge(inNode, inEdge);
                    }
                    break;
                // Find edge
                case 4:
                    {
                        int inNode; int inEdge;
                        inNode = checkInt("On what node is your edge located?  ");
                        inEdge = checkInt("What edge are you looking for?  ");

                        if (ourGraph.hasEdge(inNode, inEdge)) {
                            cout << "That edge exists!" << endl;
                        } else {
                            cout << "That edge does not exist!" << endl;
                        }
                    }
                    break;
                // Find out edges
                case 5:
                    {
                        int inVal;
                        inVal = checkInt("From what node should we find out edges?  ");
                        List<int> tempList = ourGraph.outEdges(inVal);
                        cout << "Out edges: " << endl;
                        tempList.displayAll();
                    }
                    break;
                // Find in edges
                case 6:
                    {
                        int inVal;
                        inVal = checkInt("From what node should we find in edges?  ");
                        List<int> tempList = ourGraph.inEdges(inVal);
                        cout << "In edges: " << endl;
                        tempList.displayAll();
                    }
                    break;
                // Display graph
                case 7:
                    ourGraph.displayGraph();
                    break;
                // Display depth first search path
                case 8:
                int inVal;
                    inVal = checkInt("What node should we start from?  ");
                    ourGraph.depthFirstSearch(inVal);
                    break;
                // Display breadth first search path
                case 9:
                    {
                        int inVal;
                        inVal = checkInt("What node should we start from?  ");
                        ourGraph.breadthFirstSearch(inVal);
                    }
                    break;
                default:
                    // Should never be reached
                    cout << "Whoops!" << endl;
            }
        } catch (Graph<int>::GraphNodeNotFound e) {
            cout << e.msg << endl;
        } catch (Graph<int>::GraphNodeDuplicate e) {
            cout << e.msg << endl;
        } catch (Graph<int>::GraphEdgeNotFound e) {
            cout << e.msg << endl;
        }

        cout << endl; // For readability
    }

    return 0;
}

//Makes sure an entered int is within a range
int checkInt(string text, int min, int max){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val>max)||val<min){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }
        cout << endl; // Print blank line for readability
    }
    return val;
}
