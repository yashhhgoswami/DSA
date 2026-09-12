class Solution {
public:
    struct Item { long long l, r, w; int idx; };
    struct State {
        long long score = 0;
        vector<int> idxs;
    };
    static bool better(const State& a, const State& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.idxs < b.idxs;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Item> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(arr.begin(), arr.end(), [](const Item& a, const Item& b) {
            return a.r < b.r;
        });
        vector<long long> rs(n);
        for (int i = 0; i < n; i++) rs[i] = arr[i].r;
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int i = 1; i <= n; i++) {
            Item& cur = arr[i - 1];
            int p = lower_bound(rs.begin(), rs.begin() + (i - 1), cur.l) - rs.begin();
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                if (k >= 1) {
                    State candidate = dp[p][k - 1];
                    candidate.score += cur.w;
                    auto it = lower_bound(candidate.idxs.begin(), candidate.idxs.end(), cur.idx);
                    candidate.idxs.insert(it, cur.idx);
                    if (better(candidate, dp[i][k])) {
                        dp[i][k] = candidate;
                    }
                }
            }
        }
        return dp[n][4].idxs;
    }
};