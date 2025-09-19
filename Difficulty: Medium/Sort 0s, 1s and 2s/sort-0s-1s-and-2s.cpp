class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low=0, mid = 0;
        int n = arr.size();
        int high = n-1;
        while(mid<=high){
            if (arr[mid] == 0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};