class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int stIdx = 0; 
        int endIdx = numbers.size() - 1;

        while(stIdx < endIdx){
            if(numbers[stIdx] + numbers[endIdx] == target){
                return {stIdx + 1, endIdx + 1};
            }else if(numbers[stIdx] + numbers[endIdx] > target){
                endIdx--;
            }else{
                stIdx++;
            }
        }
        return {};
    }
};
