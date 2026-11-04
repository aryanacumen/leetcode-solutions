class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start = 0, end = (numbers.size() - 1);

        while (start < end) {
            int psum = numbers[start] + numbers[end];
            if (psum == target) {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }
            else if (psum > target)
            {
                end--;
            }
            else if (psum < target)
            {
                start++;
            }
        }

        return ans;
    }
};