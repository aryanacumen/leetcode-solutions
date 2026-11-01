class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int n = nums.size();
        int maxFreq = 0;
        long long windowSum = 0;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            while ((1LL * (right - left + 1) * nums[right] - windowSum) > k) {
                windowSum -= nums[left];
                left++;
            }
            // update the maximum frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        return maxFreq;
    }
};