class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int low{0};
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==key) return mid;
            if(arr[low]<=arr[mid]){
                if((arr[mid]>=key)&&(arr[low]<=key)){
                    high = mid-1;
                }else{
                    low = mid + 1;
                }
            }else{
                if((arr[high]>=key)&&(arr[mid]<=key)){
                    low = mid + 1;
                }else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};