class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        int op1 = j + 1;
        int op2 = n - i;
        int op3 = (i + 1) + (n - j);
        return min({op1, op2, op3});
    }
};