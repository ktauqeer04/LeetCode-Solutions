class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int currLarge = nums[0];
        int n = nums.size();
        int count = 1;

        for(int i = 1; i < n; i++){

            if(nums[i] >= currLarge){
                count++;
                currLarge = max(nums[i], currLarge);
            }

        }

        return count;

    }
};