class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            rows[row] |= (1 << col);
        }
        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        long long ans = 2LL * (n - rows.size());
        for (auto &[row, mask] : rows) {
            if ((mask & left) == 0 && (mask & right) == 0) {
                ans += 2;
            }
            else if ((mask & left) == 0 ||
                     (mask & middle) == 0 ||
                     (mask & right) == 0) {
                ans += 1;
            }
        }
        return ans;
    }
};