class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int sum = nums[0];
        while (i < n && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }        
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(sum)) sum++;        
        return sum;
    }
};