class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLength = INT_MAX;
        long long windowSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            while (windowSum >= target) {
                minLength = min(minLength, right - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }

        if (minLength == INT_MAX) return 0;
        return minLength;
    }
};