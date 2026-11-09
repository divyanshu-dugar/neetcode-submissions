class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. For each string, I create a hash map (unordered map)
        // 2. Create a temp vector and for each string, I compare all the other hash maps (unordered map) and keep on pushing that vector in the result vector<vector<string>>
        // 3. At the end of each iteration I push the vector<string>

        unordered_map<string, vector<string>> mp;

        for(string str : strs){
            string temp = str;

            sort(temp.begin(), temp.end());

            mp[temp].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto& pair : mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
