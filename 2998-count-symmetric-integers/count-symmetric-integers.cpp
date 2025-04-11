class Solution {
public:

    bool symmetric(string str){
        int n = str.size();
        int fh = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            int num = '0' + str[i];
            if(i < n / 2){
                fh += num;
            }
            total += num;
        }

        return total - fh == fh;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            if(symmetric(to_string(i))){
                ans++;
            }
        }
        return ans;
    }
};