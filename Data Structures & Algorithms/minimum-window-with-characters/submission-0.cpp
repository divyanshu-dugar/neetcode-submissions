class Solution {
    public:
        string minWindow(string s, string t) {
                unordered_map<char, int> target;
                        unordered_map<char, int> window;

                                for (char c : t) {
                                            target[c]++;
                                                    }

                                                            int need = target.size();
                                                                    int have = 0;

                                                                            int l = 0;
                                                                                    int minLen = INT_MAX;
                                                                                            int start = 0;

                                                                                                    for (int r = 0; r < s.size(); r++) {
                                                                                                                char c = s[r];
                                                                                                                            window[c]++;

                                                                                                                                        if (target.count(c) &&
                                                                                                                                                        window[c] == target[c]) {
                                                                                                                                                                        have++;
                                                                                                                                                                                    }

                                                                                                                                                                                                while (have == need) {
                                                                                                                                                                                                                // Update shortest window
                                                                                                                                                                                                                                if (r - l + 1 < minLen) {
                                                                                                                                                                                                                                                    minLen = r - l + 1;
                                                                                                                                                                                                                                                                        start = l;
                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                        // Remove leftmost character
                                                                                                                                                                                                                                                                                                                        char leftChar = s[l];
                                                                                                                                                                                                                                                                                                                                        window[leftChar]--;

                                                                                                                                                                                                                                                                                                                                                        if (target.count(leftChar) &&
                                                                                                                                                                                                                                                                                                                                                                            window[leftChar] < target[leftChar]) {
                                                                                                                                                                                                                                                                                                                                                                                                have--;
                                                                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                                                                                l++;
                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                                                                                                                            return minLen == INT_MAX
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ? ""
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    : s.substr(start, minLen);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        };

