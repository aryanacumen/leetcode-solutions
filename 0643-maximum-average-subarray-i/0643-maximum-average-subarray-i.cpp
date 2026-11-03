class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = INT_MIN;
        long long windowSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            if (right - left + 1 == k) {
                maxAverage = max(maxAverage, static_cast<double>(windowSum) / k);
                windowSum -= nums[left];
                left++;
            }
        }
        return maxAverage;
    }
};