class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> mpp(26, 0);

        for (char ch : s) {
            mpp[ch - 'a']++;
        }

        string firstHalf = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            int freq = mpp[i];

            for (int j = 0; j < freq / 2; j++) {
                firstHalf += ch;
            }

            if (freq % 2 != 0 && mid.empty()) {
                mid = ch;
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + mid + secondHalf;
    }
};
