class Solution {
public:
    int differenceOfSums(int n, int m) {
        int c1 = 0, c2 = 0;

        for(int i = 1; i <= n; i++){
            if(i % m){
                c1 += i;
            }else{
                c2 += i;
            }
        }
        return c1 - c2;
    }
};