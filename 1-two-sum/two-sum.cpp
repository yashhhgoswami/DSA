class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for (int i = 0; i<n; i++){
            int num = nums[i];
            int jada = target - num;
            if (mpp.find(jada) != mpp.end()){
                return{mpp[jada], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};