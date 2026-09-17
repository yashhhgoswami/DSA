class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = INT_MAX / 2;
        vector<int> dp(n, INF);
        int ans = INF;
        int left = 0, sum = 0;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            dp[right] = (right > 0) ? dp[right - 1] : INF;
            if (sum == target) {
                int curLen = right - left + 1;
                if (left > 0 && dp[left - 1] < INF) {
                    ans = min(ans, dp[left - 1] + curLen);
                } 
                dp[right] = min(dp[right], curLen);
            }
        }
        return ans == INF ? -1 : ans;
    }
};