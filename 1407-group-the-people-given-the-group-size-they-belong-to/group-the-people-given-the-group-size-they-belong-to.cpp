class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int,vector<int>>mpp;
        vector<vector<int>>ans;
        for(int i = 0; i < nums.size(); i++){
            if(mpp[nums[i]].size() == nums[i]){
                ans.push_back(mpp[nums[i]]);
                mpp.erase(nums[i]);
            }
            mpp[nums[i]].push_back(i);
        }
        for(const auto &[size, vec] : mpp){
            ans.push_back(vec);
        }

        return ans;
    }
};