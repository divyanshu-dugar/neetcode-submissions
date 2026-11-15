class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp(nums.begin(), nums.end());
        int maxVal = 0;
        for(int i = 0; i < nums.size(); i++){
            int count = 1;
            if(!temp.count(nums[i] - 1)){
                while(temp.count(nums[i] + count)){
                    count++;
                }
                maxVal = max(count, maxVal);
            }
        }
        return maxVal;
    }
};
