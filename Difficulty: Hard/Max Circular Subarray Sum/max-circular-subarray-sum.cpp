class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int max_kadane = arr[0], curr_max = arr[0];
        int total = arr[0], curr_min = arr[0], min_kadane = arr[0];
        for (int i = 1; i < n; ++i) {
            curr_max = max(arr[i], curr_max + arr[i]);
            max_kadane = max(max_kadane, curr_max);
            curr_min = min(arr[i], curr_min + arr[i]);
            min_kadane = min(min_kadane, curr_min);
            total += arr[i];
        }
        if (max_kadane < 0) return max_kadane;
        return max(max_kadane, total - min_kadane);
    }
};