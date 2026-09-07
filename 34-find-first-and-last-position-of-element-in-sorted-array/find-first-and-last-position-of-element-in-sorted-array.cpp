class Solution {
public:
    int findFirst(vector<int>& nums, int key, int n) {
        int start = 0;
        int end = n - 1;
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                res = mid;
                end = mid - 1;
            }
            else if (key < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return res;
    }
    int findLast(vector<int>& nums, int key, int n) {
        int start = 0;
        int end = n - 1;
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                res = mid;
                start = mid + 1;
            }
            else if (key < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = findFirst(nums, target, n);
        int last = findLast(nums, target, n);
        return {first, last};
    }
};