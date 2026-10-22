class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return nums[0] == 0 ? 0 : 1;

        int o = -1, s = nums[0];
        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (s + i) % n) inc = false;
            if (nums[i] != ((s - i) % n + n) % n) dec = false;
        }
        if (inc) o = 0;
        else if (dec) o = 1;
        else return -1;

        vector<int> dist(2 * n, -1);
        auto id = [&](int oo, int ss) { return oo * n + ((ss % n) + n) % n; };
        queue<pair<int,int>> q;
        dist[id(o, s)] = 0;
        q.push({o, ((s % n) + n) % n});

        while (!q.empty()) {
            auto [co, cs] = q.front(); q.pop();
            int d = dist[id(co, cs)];
            if (co == 0 && cs == 0) return d;

            int ls = (co == 0) ? cs + 1 : cs - 1;
            int ns[2][2] = {{co, ls}, {1 - co, (co == 0) ? cs - 1 : cs + 1}};
            for (auto& p : ns) {
                int k = id(p[0], p[1]);
                if (dist[k] == -1) {
                    dist[k] = d + 1;
                    q.push({p[0], ((p[1] % n) + n) % n});
                }
            }
        }
        return 0;
    }
};