class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans = INT_MAX;
        int idx;
        int low{0};
        int high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[low]<=arr[high]){
                if(ans>arr[low]){
                    ans = arr[low];
                    idx=low;
                }
                break;
            }
            if(arr[low]<= arr[mid]){
                if(ans>arr[low]){
                    ans = arr[low];
                    idx = low;
                }
                
                low = mid + 1;
            }else{
                if(ans>arr[mid]){
                    ans = arr[mid];
                    idx = mid;
                }
                
                high = mid -1;
            }
        }
        return idx;
    }
};
