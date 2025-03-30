class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]] = i;
        }

        vector<int>ans;
        int partitioning = 0;

        int j = 0;
        for(int i = 0; i < s.size(); i++){

            partitioning = max(partitioning, mpp[s[i]]);
            if(partitioning == i){
                ans.push_back(i - j + 1);
                j = i + 1;
            }

        }

        return ans;

    }
};