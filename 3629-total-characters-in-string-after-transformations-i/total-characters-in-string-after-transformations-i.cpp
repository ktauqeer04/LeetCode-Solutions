class Solution {
public:

    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int>mpp(26, 0);
        int n = s.size();
        
        for(char &ch : s){
            mpp[ch - 'a']++;
        }

        for(int cnt = 1; cnt <= t; cnt++){
            vector<int>temp(26, 0);

            for(int i = 0; i < 26; i++){
                char ch = i + 'a';
                int freq = mpp[i];
                if(ch != 'z'){
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % MOD; 
                }else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % MOD;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % MOD;
                }
            }
            mpp = move(temp);
        }

        int count = 0;

        for(int i = 0; i < 26; i++){
            count = (count + mpp[i]) % MOD;
        }

        return count;

    }
};