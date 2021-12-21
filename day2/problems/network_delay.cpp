class Solution {
   public:
    void addEdge(vector<pair<int, int>> adj[], vector<vector<int>>& times) {
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
    }
    int dijkstra(vector<pair<int, int>> adj[], int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int prev = pq.top().second;
            pq.pop();

            for (pair<int, int>& v : adj[prev]) {
                int next = v.first;
                int nextDist = v.second;
                if (dist[next] > dist[prev] + nextDist) {
                    dist[next] = dist[prev] + nextDist;
                    pq.push({dist[next], next});
                }
            }
        }
        bool flag = true;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
            if (dist[i] == INT_MAX) {
                flag = false;
                break;
            }
            ans = max(ans, dist[i]);
        }
        if (!flag)
            return -1;
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        addEdge(adj, times);
        return dijkstra(adj, n, k);
    }
};