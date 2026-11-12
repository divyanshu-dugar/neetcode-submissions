class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        for(string str : strs){
            encodedString += to_string(str.length()) + "#" + str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {

        vector<string> decodedString;

        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            string temp = s.substr(j + 1, length);
            decodedString.push_back(temp);

            i = j + 1 + length;
        }

        return decodedString;
    }
};
