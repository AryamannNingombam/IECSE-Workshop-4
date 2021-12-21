#include <iostream>
#include <vector>
#include <map>
using namespace std;

// undirected graph
class Graph
{
private:
    // total elements in the graph;
    int elements;
    map<int, vector<int>> adj;

public:
    Graph(int elements)
    {
        this->elements = elements;
    }
    void addEdge(int u, int v)
    {
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }
    void printGraph()
    {
        for (int v = 0; v < this->elements; ++v)
        {
            cout << "\n Adjacency list of vertex "
                 << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            printf("\n");
        }
    }
};

// A utility function to print the adjacency list
// representation of graph

// Driver code
int main()
{
    auto *G = new Graph(5);
    G->addEdge(0, 1);
    G->addEdge(0, 4);
    G->addEdge(1, 2);
    G->addEdge(1, 3);
    G->addEdge(1, 4);
    G->addEdge(2, 3);
    G->addEdge(3, 4);
    G->printGraph();
    free(G);
    return 0;
}
