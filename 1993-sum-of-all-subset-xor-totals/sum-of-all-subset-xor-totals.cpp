class Solution {
public:

    int solve(vector<int>&nums, int idx, int currentXor){
        if(idx == nums.size()){
            return currentXor;
        }
        int take = solve(nums, idx + 1, nums[idx] ^ currentXor);
        int nottake = solve(nums, idx + 1, currentXor);

        return take + nottake;
    }

    int subsetXORSum(vector<int>& nums) {

        return solve(nums, 0, 0);
    }
};