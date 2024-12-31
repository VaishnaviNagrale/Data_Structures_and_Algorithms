class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        //{stops,{node,cost}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!pq.empty()) {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int cost = pq.top().second.second;
            pq.pop();
            if (stops > k) {
                continue;
            }
            for (auto it : adj[node]) {
                int v = it.first;
                int ncost = it.second;
                if (cost + ncost < dist[v] && stops <= k) {
                    dist[v] = cost + ncost;
                    pq.push({stops + 1, {v, dist[v]}});
                }
            }
        }
        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};