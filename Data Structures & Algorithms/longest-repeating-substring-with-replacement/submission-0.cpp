class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int idx = s[right] - 'A';
            ++count[idx];
            maxFreq = max(maxFreq, count[idx]);

            while ((right - left + 1) - maxFreq > k) {
                --count[s[left] - 'A'];
                ++left;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};