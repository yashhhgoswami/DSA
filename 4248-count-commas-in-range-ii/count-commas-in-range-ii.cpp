class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lower = 1, upper = 9;
        for (int d = 1; d <= 18; d++) {
            if (lower > n) break;
            long long hi = min(upper, n);
            long long commas = (d - 1) / 3;
            total += (hi - lower + 1) * commas;
            lower = upper + 1;
            upper = upper * 10 + 9;
        }
        return total;
    }
};