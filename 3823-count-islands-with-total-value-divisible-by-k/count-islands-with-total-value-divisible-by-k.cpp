class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 0) continue;

                long long total = 0;
                vector<pair<int, int>> stk;
                stk.push_back({i, j});
                total += grid[i][j];
                grid[i][j] = -1;

                while (!stk.empty()) {
                    auto [x, y] = stk.back();
                    stk.pop_back();
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] <= 0) continue;
                        total += grid[nx][ny];
                        grid[nx][ny] = -1;
                        stk.push_back({nx, ny});
                    }
                }

                if (total % k == 0) count++;
            }
        }
        return count;
    }
};