class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m > 0 && n > 0) {
            if (nums1[m-1] > nums2[0]) {
                swap(nums1[m-1], nums2[0]);
                sort(nums1.begin(), nums1.begin() + m);
                sort(nums2.begin(), nums2.begin() + n);
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};