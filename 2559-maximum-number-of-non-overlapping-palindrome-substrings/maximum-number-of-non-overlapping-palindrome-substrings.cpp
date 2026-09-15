class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            isPal[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    isPal[i][j] = (j - i == 1) || isPal[i + 1][j - 1];
                }
            }
        }
        vector<int> dp(n + 1, 0);
        for (int i = k; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (isPal[i - k][i - 1]) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }
            if (i >= k + 1 && isPal[i - k - 1][i - 1]) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }
        return dp[n];
    }
};