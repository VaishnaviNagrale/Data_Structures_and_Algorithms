typedef long long int ll;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adj[n];
        for (int i = 0; i < roads.size(); i++) {
            ll u = roads[i][0];
            ll v = roads[i][1];
            ll w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        //{dis,node}
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        pq.push({0, 0});

        vector<ll> dist(n, LONG_MAX);
        dist[0] = 0;

        vector<ll> ways(n, 0);
        ways[0] = 1;

        int mod = (ll)1e9 + 7;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll dis = it.first;
            ll node = it.second;

            for (auto itr : adj[node]) {
                ll v = itr.first;
                ll ndis = itr.second;
                if (dis + ndis < dist[v]) {
                    dist[v] = dis + ndis;
                    ways[v] = ways[node] % mod;
                    pq.push({dist[v], v});
                } else if (dis + ndis == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};