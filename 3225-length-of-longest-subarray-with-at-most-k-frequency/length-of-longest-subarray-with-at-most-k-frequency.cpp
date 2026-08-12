class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq.reserve(nums.size() * 2);
        freq.max_load_factor(0.25);        
        int left = 0, best = 0;
        int n = nums.size();       
        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;           
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }           
            best = max(best, right - left + 1);
        }        
        return best;
    }
};