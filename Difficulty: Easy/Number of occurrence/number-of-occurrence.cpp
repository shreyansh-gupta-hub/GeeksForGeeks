class Solution {
  public:
    int firstoccurence(vector<int>& arr, int target){
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] ==  target){
                ans = mid;
                high = mid-1;
            }else if(arr[mid]> target){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
    int lastoccurence(vector<int>& arr, int target){
        int ans = -1;
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] ==  target){
                ans = mid;
                low = mid + 1;
            }else if(arr[mid]> target){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        if (firstoccurence(arr,target) == -1){
            return 0;
        }
        return (lastoccurence(arr,target)-firstoccurence(arr,target)+1);
    }
};
