#include <iostream>
#include <vector>

using namespace std;

// undirected graph
class Graph
{
private:
    // total elements in the graph;
    int elements;
    vector<vector<bool>> adj;

public:
    Graph(int elements)
    {
        this->elements = elements;
        this->adj = vector<vector<bool>>(elements, vector<bool>(elements));
    }
    void addEdge(int u, int v)
    {
        this->adj[u][v] = 1;
        this->adj[v][u] = 1;
    }
    void printGraph()
    {

        for (int i = 0; i < this->elements; i++)
        {
            for (int j = 0; j < this->elements; j++)
            {
                if (this->adj[i][j])
                {
                    cout << i << ' ' << j << " connected\n";
                }
            }
        }
    }
};

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
