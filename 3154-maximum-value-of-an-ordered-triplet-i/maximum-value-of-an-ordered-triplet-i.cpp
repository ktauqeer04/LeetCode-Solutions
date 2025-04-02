class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n, 0);

        for(int i = n-2; i >= 1; i--){
            leftMax[i] = max(leftMax[i + 1], nums[i + 1]);
        }

        long long maxElement = nums[0];
        long long ans = 0;

        for(int i = 1; i < n - 1; i++){
            cout << maxElement << ' ' << nums[i] << ' ' << leftMax[i] << endl;
            ans = max(ans, (long long)((maxElement - nums[i]) * leftMax[i]));
            maxElement = max(maxElement, (long long)nums[i]);
        }

        return ans < 0 ? -1 : ans;

    }
};