class Solution {
public:

    int digitToNum(int number){
        
        int sum = 0;
        while(number > 0){
            sum += number % 10;
            number /= 10;
        }

        return sum;

    }

    int countLargestGroup(int n) {

        unordered_map<int,int>countOfSingularDigits;
        int maxSize = 0;
        int count = 0;

        for(int i = 1; i <= n; i++){
        
            int num = digitToNum(i);
            countOfSingularDigits[num]++;
            maxSize = max(maxSize, countOfSingularDigits[num]);

        }

        for(auto &[num, freq] : countOfSingularDigits){
            if(maxSize == freq){
                count++;
            }
        }

        return count;
    }
};