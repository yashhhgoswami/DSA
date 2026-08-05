class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        vector<int> suspicious(n, 0);
        queue<int> q;
        q.push(k);
        suspicious[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        for (auto &e : invocations) {
            int a = e[0], b = e[1];
            if (!suspicious[a] && suspicious[b]) {
                vector<int> all;
                all.reserve(n);
                for (int i = 0; i < n; i++) all.push_back(i);
                return all;
            }
        }

        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) ans.push_back(i);
        }
        return ans;
    }
};