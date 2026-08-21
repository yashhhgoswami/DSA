class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int minCoin = *min_element(coins.begin(), coins.end());
        long long lo = 1, hi = (long long)k * minCoin;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countUpTo(coins, mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }   
private:
    long long countUpTo(vector<int>& coins, long long x) {
        int n = coins.size();
        long long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = std::__gcd(l, (long long)coins[i]);
                    long long term = l / g * coins[i];
                    if (term > x) {
                        valid = false;
                        break;
                    }
                    l = term;
                }
            }
            if (!valid) continue;
            int bits = __builtin_popcount(mask);
            long long cnt = x / l;
            if (bits % 2 == 1) total += cnt;
            else total -= cnt;
        }
        return total;
    }
};