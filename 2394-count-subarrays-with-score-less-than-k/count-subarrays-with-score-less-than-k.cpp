class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;

        long long product = 1;
        long long sum = 0;
        long long ans = 0;

        while(j < n){

            sum += nums[j];
            product = sum * (j - i + 1);


            while(product >= k && i <= j){

                sum -= nums[i];
                i++;
                product = sum * (j - i + 1);

            }

            ans += (j - i + 1);    

            j++;

        }

        // cout << j << ' ' << i << endl;

        // if(product >= k){
        //     ans += ((j - i) * (j - i + 1)) / 2;
        // }

        // ans += ((j - i) * (j - i + 1)) / 2;

        return ans;

    }
};