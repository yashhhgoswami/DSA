class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int insertions = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    insertions++;
                    i += 1;
                }
                
                if (open > 0) {
                    open--;
                } else {
                    insertions++;
                }
            }
        }
        return insertions + 2 * open;
    }
};