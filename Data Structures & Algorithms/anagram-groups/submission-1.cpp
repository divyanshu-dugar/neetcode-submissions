class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;


        for(string word: strs){
            int freq[26] = {};

            for(char letter: word){
                freq[letter - 'a']++;
            }

            string index = "";

            for(int i = 0; i < 26; i++){
                index += "#" + to_string(freq[i]);
            }

            group[index].push_back(word);
        }

        vector<vector<string>> ans;

        for(auto& pair : group){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
