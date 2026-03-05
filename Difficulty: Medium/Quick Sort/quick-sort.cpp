
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int part = partition(arr, low, high);
            quickSort(arr, low, part - 1);
            quickSort(arr, part + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];  
        int i = low + 1;  
        int j = high;
        while (i <= j) {
            while (i <= high && arr[i] <= pivot) {
                i++; 
            }
            while (arr[j] > pivot) {
                j--; 
            }
            if (i < j) {
                swap(arr[i], arr[j]); 
            }
        }
        swap(arr[low], arr[j]); 
        return j;
    }
};
