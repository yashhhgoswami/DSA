class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        int maxBalance = m + n;
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(maxBalance + 1, false)));
        if (grid[0][0] == '(') dp[0][0][1] = true;
        else return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int delta = (grid[i][j] == '(') ? 1 : -1;
                for (int b = 0; b <= maxBalance; b++) {
                    bool fromUp = (i > 0) && dp[i-1][j][b];
                    bool fromLeft = (j > 0) && dp[i][j-1][b];
                    if (fromUp || fromLeft) {
                        int nb = b + delta;
                        if (nb >= 0 && nb <= maxBalance) {
                            dp[i][j][nb] = true;
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};