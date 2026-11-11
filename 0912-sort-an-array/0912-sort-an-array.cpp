class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    // divide the array recursively, sort each half, then merge
    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        // divide
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        // conquer
        merge(arr, low, mid, high);
    }

    // sort and merge the two halves
    void merge(vector<int> &arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        // temp array to hold sorted values
        vector<int> temp;
        temp.reserve(high - low + 1);

        // sort values and append to the temp array
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            }
            else temp.push_back(arr[right++]);
        }
        
        // append remaining values of left half (if any)
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        // append remaining values of right half (if any)
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // overwrite original array with temp array
        for (int i = 0; i < temp.size(); i++) {
            arr[i + low] = temp[i];
        }
    }
};