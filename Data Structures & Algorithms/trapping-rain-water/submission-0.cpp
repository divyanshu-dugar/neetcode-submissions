class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixArr(n);
        vector<int> postfixArr(n);

        int maxVal = 0;
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, height[i]);
            prefixArr[i] = maxVal;
        }

        maxVal = 0;
        for(int i = n - 1; i >= 0; i--){
            maxVal = max(maxVal, height[i]);
            postfixArr[i] = maxVal;
        }

        int totalWater = 0;
        for(int i = 1; i < n - 1; i++){
            totalWater += min(prefixArr[i], postfixArr[i]) - height[i];
        }

        return totalWater;
    }
};
