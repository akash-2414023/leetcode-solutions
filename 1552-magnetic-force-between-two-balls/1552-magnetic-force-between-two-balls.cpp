class Solution {
public:
    bool isPossible(vector<int>& arr,long long dist ,int m){
        int n = arr.size();
        int count = 1;
        int last = arr[0];
        for(int i = 1; i < n ; i++){
            if(arr[i] - last >= dist){
                count++;
                last = arr[i];
                if(count >= m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int m) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        long long low = 1;
        long long high = arr[n-1] - arr[0];
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            bool isValid = isPossible(arr,mid,m);
            if(isValid){
                low = mid + 1;
                
            }else high = mid - 1;
        }
        return high;
    }
};