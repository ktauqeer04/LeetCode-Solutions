class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>prev_idx(n, -1);

        int maxLen = 1;
        int lci = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }

                    if(dp[i] > maxLen){
                        maxLen = dp[i];
                        lci = i;
                    }
                }
            }
        }

        vector<int>ans;

        while(lci != -1){
            ans.push_back(nums[lci]);
            lci = prev_idx[lci];
        }

        return ans;

    }
};