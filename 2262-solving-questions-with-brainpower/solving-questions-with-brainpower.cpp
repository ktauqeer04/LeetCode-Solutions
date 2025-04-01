class Solution {
public:

    // long long dp[];
    long long dp[100001];

    long long solve(vector<vector<int>>& questions, int i){
        if(i >= questions.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        long long take = questions[i][0] + solve(questions, i + questions[i][1] + 1);
        long long skip = solve(questions, i + 1);

        return dp[i] = max(take, skip);

    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return solve(questions, 0);
    }
};