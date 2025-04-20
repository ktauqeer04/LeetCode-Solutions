class Solution {
public:
    int numRabbits(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int>mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        long long ans = 0;

        for(auto [num, freq]: mpp){
            while(freq > 0){
                ans += num + 1;
                freq -= num + 1;
            }
        }

        return static_cast<int>(ans);
    }
};
