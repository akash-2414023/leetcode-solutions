class Solution {
public:
    string compare(string a, string b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                return a;
            } else if (a[i] > b[i]) {
                return b;
            }
        }
        return a;
    }
    string longestWord(vector<string>& words) {
        int n = words.size();
        string ans = "";
        unordered_set<string> st(words.begin(), words.end());
        for (int i = 0; i < n; i++) {
            string ch = words[i];
            int l = ch.size();
            string temp = "";
            bool check = true;
            for (int j = 0; j < l; j++) {
                temp += ch[j];

                if (st.find(temp) == st.end()) {
                    check = false;
                    break;
                }
            }
            if (check) {

                if (ans == "") {
                    ans = ch;
                } else if (ans.size() < l) {
                    ans = ch;
                } else if (ans.size() == l) {
                    ans = compare(ans, ch);
                }
            }
        }
        return ans;
    }
};