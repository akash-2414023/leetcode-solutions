class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        for (int i = 0; i < n; i++) {
            title[i] = tolower(title[i]);
        }
        for (int i = 0; i < n; i++) {
            if (i == 0 || title[i - 1] == ' ') {
                if (i + 2 < n && title[i + 1] != ' ' && title[i + 2] != ' ') {
                    title[i] = toupper(title[i]);
                }
            }
        }
        return title;
    }
};