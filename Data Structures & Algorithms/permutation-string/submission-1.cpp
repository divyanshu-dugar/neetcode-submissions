class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // create a sliding window of the size equal to the size of the s1, and then keep track of the frequency.

        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> freqs1(26);
        vector<int> freqs2(26);

        for(int i = 0; i < n; i++){
            freqs1[s1[i] - 'a']++;
            freqs2[s2[i] - 'a']++;
        }

        if(freqs1 == freqs2) return true;

        for(int i = n; i < m; i++){
            freqs2[s2[i] - 'a']++;
            freqs2[s2[i - n] - 'a']--;

            if(freqs1 == freqs2) return true;
        }

        return false;
    }
};
