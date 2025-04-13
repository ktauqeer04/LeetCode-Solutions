class Solution {
public:

    const int MOD = 1e9 + 7;

    long long power(long long number, long long raise){

        if(raise == 0){
            return 1;
        }

        long long half = power(number, raise / 2);
        long long ans = ((half % MOD) * (half % MOD)) % MOD;

        if(raise % 2 == 1){
            ans = ans * number;
        }

        return ans;

    }

    int countGoodNumbers(long long n) {
        long long odd = power(4, n / 2);
        long long even = power(5, ((n + 1)/2));
        return ((odd % MOD) * (even % MOD)) % MOD;
    }
};