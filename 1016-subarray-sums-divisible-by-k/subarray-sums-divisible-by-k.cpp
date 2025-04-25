class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int count = 0;
        int cumSum = 0;
        for(int i =0 ;i < nums.size(); i++){
            cumSum = (cumSum + (nums[i] % k) + k) % k;
            int div = cumSum % k;
            cout << div << endl;
            count += mpp[div];
            mpp[div]++;
        }

        return count;
    }
};