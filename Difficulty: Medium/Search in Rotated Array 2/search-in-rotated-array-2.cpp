class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code here
        int low{0};
        int high = arr.size()-1;
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(arr[mid]==key) return true;
            
            if((arr[mid]==arr[low])&&(arr[mid]==arr[high])){
                low++;
                high--;
                continue;
            }
            if(arr[low]<=arr[mid]){
                if((arr[mid]>=key)&&(arr[low]<=key)){
                    high = mid -1;
                }else{
                    low = mid +1;
                }
            }else{
                if((arr[high]>=key)&&(arr[mid]<=key)){
                    low = mid +1;
                }else{
                    high = mid -1;
                }
            }
        }
        return false;
    }
};