class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                int best = INF;
                for (int d = 1; d < L; d++) {
                    if (L % d != 0) continue;
                    int m = L / d, changes = 0;
                    for (int g = 0; g < d; g++) {
                        for (int t = 0; t < m / 2; t++) {
                            if (s[i + g + t * d] != s[i + g + (m - 1 - t) * d]) changes++;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 1; i <= n; i++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[p - 1][j] >= INF || cost[j][i - 1] >= INF) continue;
                    dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};