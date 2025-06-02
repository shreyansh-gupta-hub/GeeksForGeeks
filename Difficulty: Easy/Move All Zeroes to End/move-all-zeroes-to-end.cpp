// User function template for C++
class Solution {
  public:
    void swap (vector<int>& arr, int x, int y){
        int temp{};
        temp = arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
    }
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int count{0};
        for (int i=0; i<arr.size();i++){
            if (arr[i]!=0){
                swap(arr,i,count);
                count++;
            }
        }
    }
};