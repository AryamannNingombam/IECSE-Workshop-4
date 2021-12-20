// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        this->adj = new vector<int>[V];
    }

    void addEdge(int v, int w)
    {
        this->adj[v].push_back(w); // Add w to v’s list.
        this->adj[w].push_back(v); // Add v to w’s list.
    }

    void BFS(int s)
    {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        vector<int>::iterator i;

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (i = this->adj[s].begin(); i != this->adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
    }
};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
