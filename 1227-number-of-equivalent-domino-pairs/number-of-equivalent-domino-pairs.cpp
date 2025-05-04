class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int n = dominoes.size();
        map<pair<int,int>,int>mpp;
        int count = 0;

        for(int i = 0; i < n; i++){

            int num1 = min(dominoes[i][0], dominoes[i][1]);
            int num2 = max(dominoes[i][0], dominoes[i][1]);

            mpp[{num1, num2}]++;

        }

        for(const auto &it : mpp){
            pair<int,int>p = it.first;
            count += (mpp[p] * (mpp[p] - 1)) / 2;
        }

        return count;
    }
};