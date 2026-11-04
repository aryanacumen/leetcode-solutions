class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            maxWater = max(maxWater, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return maxWater;
    }
};