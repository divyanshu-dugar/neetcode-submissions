class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        int s1Count[26] = {0};
        int s2Count[26] = {0};
        int windowSize = static_cast<int>(s1.size());

        for (int i = 0; i < windowSize; ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        for (int right = windowSize; right < static_cast<int>(s2.size()); ++right) {
            if (matches == 26) {
                return true;
            }

            // Include incoming character at `right`
            int inIdx = s2[right] - 'a';
            s2Count[inIdx]++;
            if (s2Count[inIdx] == s1Count[inIdx]) {
                matches++;
            } else if (s2Count[inIdx] - 1 == s1Count[inIdx]) {
                matches--;
            }

            // Exclude outgoing character at `right - windowSize`
            int outIdx = s2[right - windowSize] - 'a';
            s2Count[outIdx]--;
            if (s2Count[outIdx] == s1Count[outIdx]) {
                matches++;
            } else if (s2Count[outIdx] + 1 == s1Count[outIdx]) {
                matches--;
            }
        }

        return matches == 26;
    }
};