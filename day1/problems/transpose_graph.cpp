//Aditya_Chandra
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void addEdge(vector<int> adj[], int parent, int child) {
    adj[parent].push_back(child);
}

void displayGraph(vector<int> adj[], int v) {
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << "  ";

        cout << endl;
    }
}

void transposeGraph(vector<int> adj[], vector<int> transpose[], int v) {
    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 1);

    vector<int> transpose[v];
    displayGraph(adj, v); cout << endl;
    transposeGraph(adj, transpose, v);
    displayGraph(transpose, v);

    return 0;
}