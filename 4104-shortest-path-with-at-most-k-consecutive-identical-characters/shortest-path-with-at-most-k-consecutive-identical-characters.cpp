class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        vector<long long> dist((long long)n * k, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, id] = pq.top(); pq.pop();
            if (d > dist[id]) continue;
            int u = id / k, run = id % k + 1;
            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {
                int nr;
                if (labels[v] == labels[u]) {
                    nr = run + 1;
                    if (nr > k) continue;
                } else {
                    nr = 1;
                }
                int nid = v * k + (nr - 1);
                if (d + w < dist[nid]) {
                    dist[nid] = d + w;
                    pq.push({dist[nid], nid});
                }
            }
        }
        return -1;
    }
};