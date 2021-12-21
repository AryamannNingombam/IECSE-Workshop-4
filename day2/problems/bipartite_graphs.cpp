//Aditya_Chandra
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//no adjacent graph should have the same colour
//any graph which has a odd length cycle cannot be bipartite.
// B-G-B-G-B-G-B
// Prerequisites:
// bfs algo needed
// predict a cycle using bfs
// colour adjacent nodes with the exact opposite colour
// if you find some node with another color it cannot be a birpartite graph
bool bipartiteBFS(int src, vector<int> adj[], vector<int>& color) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bipartiteBFS(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int u, v;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}