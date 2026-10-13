class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) {
            sq[i] = (long long)nums[i] * nums[i];
        }
        sort(sq.begin(), sq.end(), greater<long long>());

        int plusCount = (n + 1) / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < plusCount) ans += sq[i];
            else ans -= sq[i];
        }
        return ans;
    }
};