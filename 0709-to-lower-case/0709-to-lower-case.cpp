class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        string ans = "";
        for(char ch : s){
            ans += tolower(ch);
        }
        return ans;
    }
};