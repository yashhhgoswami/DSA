class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = INT_MIN;

            for (int s = 0; s < n && ok; s += k) {
                int descents = 0;
                int mn = nums[s], mx = nums[s];

                for (int i = s; i < s + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                    int nxt = (i + 1 < s + k) ? nums[i + 1] : nums[s];
                    if (nums[i] > nxt) descents++;
                }

                if (descents > 1 || prevMax > mn) ok = false;
                prevMax = mx;
            }

            if (ok) total += k;
        }

        return total;
    }
};