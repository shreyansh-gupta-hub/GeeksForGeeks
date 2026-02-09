class Solution {
  public:
    int numgasstation(long double dist, vector<int> &arr){
        int cnt{0};
        for(int i{1}; i<arr.size(); i++){
            int num = (arr[i]-arr[i-1])/dist;
            if(((arr[i]-arr[i-1])/dist)==num*dist){
                num--;
            }
            cnt +=num;
        }
        return cnt;
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        long double low = 0;
        long double high =0;
        for(int i{0}; i<n-1;i++){
            high = max(high,(long double)(stations[i+1]-stations[i]));
        }
        long double diff = 1e-6;
        while(high-low>diff){
            long double mid = (low)+(high-low)/2.0;
            int cnt = numgasstation(mid,stations);
            if(cnt>K){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};