class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        
        // for(int i=0;i<n;i++){
        //     map<char,int> mp;
        //     for(int j=i;j<n;j++){
        //         if(mp[s[j]]==1) break;
        //         mp[s[j]]++;
        //         maxlen=max(maxlen,j-i+1);
                
        //     }
            
        // }
        // return maxlen;
        int l=0,r=0;
        map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};