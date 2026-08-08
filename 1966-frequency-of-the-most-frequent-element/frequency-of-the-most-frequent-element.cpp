class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();     
        int i = 0;
        long long windowSum = 0;
        int maxFreq = 1;
        for (int j = 0; j < n; j++) {
            windowSum += nums[j];
            long long windowSize = j - i + 1;          
            while ((long long)nums[j] * windowSize - windowSum > k) {
                windowSum -= nums[i];
                i++;
                windowSize = j - i + 1;
            }
            maxFreq = max(maxFreq, (int)windowSize);
        }
        
        return maxFreq;
    }
};