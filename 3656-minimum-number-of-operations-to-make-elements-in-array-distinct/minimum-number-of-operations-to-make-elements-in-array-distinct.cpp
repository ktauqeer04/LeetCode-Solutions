class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mpp;

        for(int i = n-1; i >= 0; i--){
            if(mpp.contains(nums[i])){
                ans = ((i + 1) % 3 == 0) ? (i + 1) / 3 : ((i + 1) / 3) + 1;
                return ans;
            }
            mpp[nums[i]] = i;
        }

        return ans;
    }
};