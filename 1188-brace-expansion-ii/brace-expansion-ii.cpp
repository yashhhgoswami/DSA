class Solution {
public:
    string s;
    int pos;
    set<string> parseExpr() {
        set<string> result;
        result.insert("");
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            set<string> termSet = parseTerm();
            set<string> newResult;
            for (auto& a : result) {
                for (auto& b : termSet) {
                    newResult.insert(a + b);
                }
            }
            result = newResult;
        }
        return result;
    }
    set<string> parseTerm() {
        if (s[pos] == '{') {
            pos++;
            set<string> unionSet;
            while (true) {
                set<string> exprSet = parseExpr();
                for (auto& e : exprSet) unionSet.insert(e);
                if (pos < (int)s.size() && s[pos] == ',') {
                    pos++;
                    continue;
                }
                break;
            }
            pos++;
            return unionSet;
        } else {
            string letter(1, s[pos]);
            pos++;
            return {letter};
        }
    }
    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> res = parseExpr();
        return vector<string>(res.begin(), res.end());
    }
};