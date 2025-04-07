class Solution {
public:

    int dp[201][20001];

    bool solve(vector<int>&nums, int totalSum, int i, int currSum){

        if(i == nums.size()){
            if(totalSum - currSum == currSum) return true;
            return false;
        }
        
        if(dp[i][currSum] != -1){
            return dp[i][currSum];
        }
 
        currSum += nums[i];
        bool take = solve(nums, totalSum, i + 1, currSum);
        currSum -= nums[i];
        bool nottake = solve(nums, totalSum, i + 1, currSum);
        
        return dp[i][currSum] = take || nottake;

    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int totalSum = 0;
        for(int &n : nums){
            totalSum += n;
        }
        return solve(nums, totalSum, 0, 0);
    }
};