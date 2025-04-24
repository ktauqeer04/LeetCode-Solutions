class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        set<int>st;
        for(int &num : nums){
            st.insert(num);
        }

        unordered_map<int,int>mpp;

        int i = 0, j = 0;
        int n = nums.size();
        int count = 0;

        while(j < n){

            mpp[nums[j]]++;

            while(mpp.size() == st.size() && i <= j){

                count += (n - j);

                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }

            j++;

        }

        return count;

    }
};