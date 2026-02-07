// User function Template for C++

class Solution {
  public:
    int maxele(int arr[],int n){
        int maxi = INT_MIN;
        for(int i{0}; i<n;i++){
            if(arr[i]>maxi) maxi = arr[i];
        }
        return maxi;
    }
    int arrsum(int weights[],int n){
        int sum = 0;
        for(int i{0}; i<n;i++){
            sum += weights[i];
        }
        return sum;
    }
    bool numdays(int weights[], int days, int cap,int n){
        int days_used = 1;
        int sum = 0;

        for (int i{0}; i<n;i++) {
            if (weights[i] > cap) return false;

            if (sum + weights[i] <= cap) {
                sum += weights[i];
            } else {
                days_used++;
                sum = weights[i];
            }
        }

        return days_used <= days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int low = maxele(arr,n);
        int high = arrsum(arr,n);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(numdays(arr,d,mid,n) == true){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
        
    }
};