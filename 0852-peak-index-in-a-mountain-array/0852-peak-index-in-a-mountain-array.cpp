class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        int peakIndex;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
            if (left == right - 1 && arr[left] > arr[right]) peakIndex = left;
            else peakIndex = right;
        }
        return peakIndex;
    }
};