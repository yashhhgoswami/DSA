class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> reach(m, vector<bitset<1024>>(n));

        reach[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<1024> prev;
                if (i > 0) prev |= reach[i - 1][j];
                if (j > 0) prev |= reach[i][j - 1];
                int g = grid[i][j];
                for (int x = 0; x < 1024; x++) {
                    if (prev[x]) reach[i][j][x ^ g] = 1;
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (reach[m - 1][n - 1][x]) return x;
        }
        return -1;
    }
};