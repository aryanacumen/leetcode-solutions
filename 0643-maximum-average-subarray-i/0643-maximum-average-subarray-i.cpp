class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxAverage = static_cast<double>(windowSum) / k;
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i-k];
            maxAverage = max(maxAverage, static_cast<double>(windowSum) / k);
        }
        
        return maxAverage;
    }
};