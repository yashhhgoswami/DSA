class Solution {
public:
    int n, LOG;
    vector<int> tin, tout, depth, base, bit;
    vector<vector<int>> up;

    void bitUpdate(int i, int x) {
        for (i++; i <= n + 1; i += i & -i) bit[i] ^= x;
    }
    int bitQuery(int i) {
        int r = 0;
        for (i++; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    int val(int u) { return base[u] ^ bitQuery(tin[u]); }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) if (diff >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
        }
        return up[0][a];
    }

    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0); tout.assign(n, 0); depth.assign(n, 0); base.assign(n, 0);
        bit.assign(n + 2, 0);
        up.assign(LOG, vector<int>(n, 0));

        int timer = 0;
        vector<int> stk, idx(n, 0);
        stk.push_back(0);
        up[0][0] = 0;
        tin[0] = timer++;
        base[0] = 1 << (s[0] - 'a');
        while (!stk.empty()) {
            int u = stk.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));
                tin[v] = timer++;
                stk.push_back(v);
            } else {
                tout[u] = timer - 1;
                stk.pop_back();
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        vector<bool> ans;
        for (auto& q : queries) {
            istringstream iss(q);
            string type; iss >> type;
            if (type == "update") {
                int u; string c;
                iss >> u >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c[0] - 'a'));
                if (delta) {
                    bitUpdate(tin[u], delta);
                    bitUpdate(tout[u] + 1, delta);
                }
                s[u] = c[0];
            } else {
                int u, v;
                iss >> u >> v;
                int l = lca(u, v);
                int mask = val(u) ^ val(v) ^ (1 << (s[l] - 'a'));
                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }
        return ans;
    }
};