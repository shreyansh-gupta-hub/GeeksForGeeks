class Solution {
  public:
    int maxarr(vector<int>& arr){
        int maxi = INT_MIN;
        for(auto i: arr){
            if(maxi<i){
                maxi = i;
            }
        }
        return maxi;
    }
    int possible(vector<int>& bloomDay, int k, int day){
        int count{0};
        int num{0};
        for (auto i :bloomDay){
            if(i<=day){
                count++;
            }else{
                num+=count/k;
                count = 0;
            }
        }
        num += count / k;
        return num;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)m * k > arr.size()) return -1;
        int low = 1;
        int high = maxarr(arr);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(arr, k, mid) >= m ){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
        
    }
};