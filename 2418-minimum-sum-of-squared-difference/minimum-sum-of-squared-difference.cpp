class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int maxD = 0;
        for (int i = 0; i < n; i++) {
            maxD = max(maxD, abs(nums1[i] - nums2[i]));
        }

        vector<long long> cnt(maxD + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }

        for (int v = maxD; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            if (k >= cnt[v]) {
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {
                cnt[v - 1] += k;
                cnt[v] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (int v = 1; v <= maxD; v++) {
            ans += cnt[v] * (long long)v * v;
        }
        return ans;
    }
};