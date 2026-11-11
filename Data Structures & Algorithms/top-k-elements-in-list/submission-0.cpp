class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<vector<int>> freqIdx(n + 1);

        for(auto& i : freq){
            freqIdx[i.second].push_back(i.first);
        }

        vector<int> ans;

        for(int i = n; i >= 0; i--){
            for(int num : freqIdx[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
