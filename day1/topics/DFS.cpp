#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
private:
    // maps can also be used to represent graphs in
    //  adjacency list representation

    // visited flags would help us know
    // which paths to not take anymore;

    map<int, bool> visited;
    map<int, vector<int>> adj;

public:
    void addEdge(int v, int w)
    {
        this->adj[v].push_back(w); // Add w to v’s list.
        this->adj[w].push_back(v); // Add v to w’s list.
    }

    void DFS(int v)
    {
        // Mark the current node as visited and
        // print it
        this->visited[v] = true;
        cout << v << " ";

        // from previous workshop
        //  if you dont understand this, you should
        //  have attended previous workshop
        vector<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!this->visited[*i])
                this->DFS(*i);
    }
};

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph *g = new Graph();
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g->DFS(2);
    free(g);
    return 0;
}

// improved by Vishnudev C
