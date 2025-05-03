class Solution {
public:

    int find(int num, vector<int>& tops, vector<int>& bottoms){

        int n = tops.size();
        int topswaps = 0, bottomswaps = 0;

        for(int i = 0; i < n; i++){

            if(tops[i] != num && bottoms[i] != num){
                return -1;
            }else if(tops[i] == num && bottoms[i] == num){
                continue;
            }else if(tops[i] == num){
                bottomswaps++;
            }else{
                topswaps++;
            }

        }

        return min(topswaps, bottomswaps);

    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        int ans = INT_MAX;

        for(int i = 1; i <= 6; i++){

            int swaps = find(i, tops, bottoms);

            if(swaps != -1){
                ans = min(ans, swaps);
            }

        }

        return ans == INT_MAX ? -1: ans;
    }
};