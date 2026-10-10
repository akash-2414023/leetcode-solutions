class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push('(');
            } 
            else {
                if (i + 1 >= n || s[i + 1] != ')') {
                    ans++;
                } 
                else {
                    i++;
                }

                if (!st.empty()) {
                    st.pop();
                } 
                else {
                    ans++;
                }
            }
        }

        return ans + 2 * st.size();
    }
};