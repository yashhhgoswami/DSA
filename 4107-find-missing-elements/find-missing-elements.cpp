class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx - mn + 1, false);
        for (int x : nums) {
            present[x - mn] = true;
        }

        vector<int> result;
        for (int v = mn; v <= mx; v++) {
            if (!present[v - mn]) {
                result.push_back(v);
            }
        }
        return result;
    }
};