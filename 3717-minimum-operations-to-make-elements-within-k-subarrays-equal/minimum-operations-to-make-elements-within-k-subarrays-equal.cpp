class Solution {
public:
    int m_;
    vector<long long> cntBit, sumBit;
    vector<int> vals;

    void add(int r, int c, long long v) {
        for (r++; r <= m_; r += r & -r) { cntBit[r] += c; sumBit[r] += v; }
    }
    void prefix(int r, long long& c, long long& s) {
        c = 0; s = 0;
        for (r++; r > 0; r -= r & -r) { c += cntBit[r]; s += sumBit[r]; }
    }
    int kth(long long k) {
        int pos = 0, LOG = 1;
        while ((1 << LOG) <= m_) LOG++;
        for (int b = LOG; b >= 0; b--) {
            int np = pos + (1 << b);
            if (np <= m_ && cntBit[np] < k) { pos = np; k -= cntBit[np]; }
        }
        return pos;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        m_ = vals.size();
        cntBit.assign(m_ + 1, 0);
        sumBit.assign(m_ + 1, 0);
        auto rankOf = [&](int v) { return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()); };

        int W = n - x + 1;
        vector<long long> cost(W);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            add(rankOf(nums[i]), 1, nums[i]);
            total += nums[i];
            if (i >= x) {
                add(rankOf(nums[i - x]), -1, -nums[i - x]);
                total -= nums[i - x];
            }
            if (i >= x - 1) {
                int r = kth((x + 1) / 2);
                long long med = vals[r];
                long long c, s;
                prefix(r, c, s);
                cost[i - x + 1] = med * c - s + (total - s) - med * (x - c);
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (dp[j - 1][i - x] < INF)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};