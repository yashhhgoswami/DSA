class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long B = budget;

        vector<int> cnt(n + 1, 0);
        long long pm = LLONG_MAX;
        for (auto& it : items) { cnt[it[0]]++; pm = min(pm, (long long)it[1]); }
        vector<int> g(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (!cnt[f]) continue;
            int s = 0;
            for (int m = f; m <= n; m += f) s += cnt[m];
            g[f] = s - 1;
        }
        vector<pair<long long, long long>> cheap;
        for (auto& it : items)
            if (g[it[0]] > 0 && it[1] < 2 * pm) cheap.push_back({it[1], g[it[0]]});
        sort(cheap.begin(), cheap.end());

        long long a = 0, spent = 0;
        for (auto& [p, gi] : cheap) {
            long long k = min(gi, (B - spent) / p);
            a += k;
            spent += k * p;
            if (k < gi) break;
        }
        return 2 * a + (B - spent) / pm;
    }
};