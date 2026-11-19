#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(heights[left], heights[right]);
            maxWater = max(maxWater, width * currentHeight);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};