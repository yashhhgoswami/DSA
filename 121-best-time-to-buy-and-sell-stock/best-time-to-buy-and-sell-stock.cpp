class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min_price = INT_MAX;
        int max_profit = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < min_price) {
                min_price = nums[i];
            } else if (nums[i] - min_price > max_profit) {
                max_profit = nums[i] - min_price;
            }
        }
        return max_profit;
    }
};