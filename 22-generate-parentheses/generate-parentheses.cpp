class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string current;
        backtrack(current, 0, 0, n);
        return result;
    }
    void backtrack(string& current, int openCount, int closeCount, int n) {
        if ((int)current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (openCount < n) {
            current.push_back('(');
            backtrack(current, openCount + 1, closeCount, n);
            current.pop_back();
        }
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(current, openCount, closeCount + 1, n);
            current.pop_back();
        }
    }
};