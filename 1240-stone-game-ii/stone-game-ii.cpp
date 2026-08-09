class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));       
        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                } else {
                    int best = INT_MAX;
                    int maxX = 2 * M;
                    for (int X = 1; X <= maxX; X++) {
                        int nm = max(M, X);
                        if (nm > n) nm = n; // cap, harmless
                        int val = dp[i + X][nm];
                        if (val < best) best = val;
                    }
                    dp[i][M] = suffix[i] - best;
                }
            }
        }       
        return dp[0][1];
    }
};