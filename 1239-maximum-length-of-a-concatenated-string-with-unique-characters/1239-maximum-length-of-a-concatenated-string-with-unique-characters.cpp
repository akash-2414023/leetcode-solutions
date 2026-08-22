class Solution {
public:
    bool hasDuplicate(string& s1 , string& s2){
        int arr[26] = {0};
        for(char ch : s1){
            if(arr[ch - 'a'] > 0){
                return true;
            }
            arr[ch - 'a']++;
        }
        for(char ch : s2){
            if(arr[ch - 'a'] > 0){
                return true;
            }
            arr[ch - 'a']++;
        }
        return false;
    }
    int solve(vector<string>& arr , int ind , string temp , int n){
        if(ind >= n){
            return temp.length();
        }
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[ind] , temp)){
            exclude = solve(arr , ind + 1 , temp , n);
        }
        else{
            exclude = solve(arr , ind + 1 , temp , n);
            include = solve(arr , ind + 1 , temp + arr[ind] , n);
        }
        return max(include , exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(arr , 0 , temp , n);
    }
};