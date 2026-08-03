class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + stoneValue[i];
        }
        vector<long long> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            long long best = LLONG_MIN;
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                long long taken = suf[i] - suf[i + k];
                long long candidate = taken - dp[i + k];
                best = max(best, candidate);
            }
            dp[i] = best;
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};