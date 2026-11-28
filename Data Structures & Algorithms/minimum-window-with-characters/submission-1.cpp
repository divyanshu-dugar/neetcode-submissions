class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tfreq;
        unordered_map<char, int> window;

        int have = 0;
        int l = 0;
        int min_length = INT_MAX;
        int start = 0;

        for(int i = 0; i < t.size(); i++){
            tfreq[t[i]]++;
        }

        int need = tfreq.size();

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            window[ch]++;

            if(tfreq.count(ch) && window[ch] == tfreq[ch]){
                have++;
            }

            while(have == need){
                int curr_min_length = i - l + 1;
                if(min_length > curr_min_length){
                    min_length = curr_min_length;
                    start = l;
                }

                char left_ch = s[l];
                window[left_ch]--;

                if(tfreq.count(left_ch) && window[left_ch] < tfreq[left_ch]){
                    have--;
                }

                l++;
            }
        }

        return min_length == INT_MAX ? "" : s.substr(start, min_length);
    }
};
