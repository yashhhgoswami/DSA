class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)sum > 9LL * num) return "";

        string res(num, '0');
        int remaining = sum;
        for (int i = 0; i < num && remaining > 0; i++) {
            int d = min(9, remaining);
            res[i] = '0' + d;
            remaining -= d;
        }
        return res;
    }
};