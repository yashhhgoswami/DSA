class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0; // range of possible balances
        
        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else { // '*'
                lo--; // treat as ')'
                hi++; // treat as '('
            }
            
            if (hi < 0) return false; // even the best case went negative -> unrecoverable
            lo = max(lo, 0); // can't have negative balance; clamp to 0 (treat '*' as empty/'(' instead of ')')
        }
        
        return lo == 0;
    }
};