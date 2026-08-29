class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && arr[j+1].first - arr[j].first <= limit) {
                j++;
            }
            int groupSize = j - i + 1;
            vector<int> indices(groupSize);
            for (int k = 0; k < groupSize; k++) {
                indices[k] = arr[i + k].second;
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < groupSize; k++) {
                result[indices[k]] = arr[i + k].first;
            }
            i = j + 1;
        }
        return result;
    }
};