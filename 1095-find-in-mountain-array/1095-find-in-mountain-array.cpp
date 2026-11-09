/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int left = 1;
        int right = n - 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int curr = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);

            if (curr < next) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        int peakIndex = left;

        // search in the ascending portion
        left = 0;
        right = peakIndex;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int curr = mountainArr.get(mid);

            if (target == curr) {
                return mid;
            }
            else if (target > curr) left = mid + 1;
            else right = mid - 1;
        }

        // search in the descending portion
        left = peakIndex + 1;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int curr = mountainArr.get(mid);

            if (target == curr) {
                return mid;
            }
            else if (target < curr) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};