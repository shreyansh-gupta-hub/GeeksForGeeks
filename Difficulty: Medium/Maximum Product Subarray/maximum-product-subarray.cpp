class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxProd = arr[0], minProd = arr[0], result = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(arr[i], arr[i] * maxProd);
            minProd = min(arr[i], arr[i] * minProd);

            result = max(result, maxProd);
        }

        return result;
    }
};