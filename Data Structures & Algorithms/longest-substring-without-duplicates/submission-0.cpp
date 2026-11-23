class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0, maxVal = 0;

        for(int i = 0; i < s.size(); i++){
            if(lastSeen.count(s[i]) && lastSeen[s[i]] >= left){
                left = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxVal = max(maxVal, i - left + 1);
        }
        return maxVal;
    }
};
