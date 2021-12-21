//Aditya_Chandra
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//checking cycle using BFS
bool cycleBFS(int i, int m, vector<int> adj[], vector<int> &visited) {
    queue<pair<int, int>> q;  // using a pair to store <current child, prev child>
    visited[i] = true;
    q.push({i, -1});
    while (!q.empty()) {  // normalBFS algo
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();

        for (auto it : adj[curr]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push({it, curr});  //if the node is not visited, we mark it visited and push it to the queue, along with its prev child
            } else if (prev != it) {
                return true;  // if the node is already visited and it is not equal to our previous node, it means that this node has been visited by another bfs tree, thus there has to be a cycle present.
            }
        }
    }
    return false;
}

//checking cycle using DFS
bool cycleDFS(int curr, int prev, vector<int> adj[], vector<int> &visited) {
    visited[curr] = 1;  // mark the current node visted 
    for (auto it : adj[curr]) { 
        if (!visited[it]) { //if not visited we go ahead.
            if (cycleDFS(it, curr, adj, visited)) return true;
        } else if (it != prev) // if its visited and its not equal to the previous node it means that this node has already been visited by another dfs tree. Hence there has to be a cycle present.
            return true; // so we return true;
    }
    return false;// if the function doesnt return after the whole process we return false.
}

bool isCycle(int m, vector<int> adj[]) {
    vector<int> visited(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            // if (cycleBFS(i, m , adj, visited)) return true;
            if (cycleDFS(i, -1, adj, visited)) return true;
        }
    }
    return false;
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

    // To check Adjacency List
    // for(int i = 1; i <= m ; i++){
    //     cout << i << " ";
    //     for(auto it: adj[i]){
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }

    isCycle(m, adj) ? cout << "YES" << endl : cout << "NO" << endl;
}