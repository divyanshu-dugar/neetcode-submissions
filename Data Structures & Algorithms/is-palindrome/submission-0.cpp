class Solution {
public:
    bool isPalindrome(string s) {
        int stIdx = 0;
        int endIdx = s.size() - 1;

        while(stIdx <= endIdx){
            while(stIdx < endIdx && !isalnum(s[endIdx])){
                endIdx--;
            }

            while(stIdx < endIdx && !isalnum(s[stIdx])){
                stIdx++;
            }

            if(tolower(s[stIdx]) != tolower(s[endIdx])){
                return false;
            }

            stIdx++;
            endIdx--;
        }
        return true;
    }
};
