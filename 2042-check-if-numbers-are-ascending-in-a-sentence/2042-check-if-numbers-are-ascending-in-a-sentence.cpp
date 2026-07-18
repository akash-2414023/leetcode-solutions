class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> arr;
        int n = s.size();
        int i = 0;
        while (i < n ) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                int j = i + 1;
                while (j < n && s[j] != ' ') {
                    num = num * 10 + (s[j] - '0');
                    j++;
                }
                arr.push_back(num);
                i = j;
            } else
                i++;
        }
        for (int k = 0; k < arr.size() - 1; k++) {
            if (arr[k] >= arr[k + 1])
                return false;
        }
        return true;
    }
};