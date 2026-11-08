class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;

        for(int i = 0; i < nums.size(); i++){
            int num2 = target - nums[i];

            if(temp.count(num2)){
                return {temp[num2], i};
            }

            temp[nums[i]] = i;
        }
        return {};
    }
};
