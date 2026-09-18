class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int,int>> validIntervals;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue;
            int end = last[c];
            bool ok = true;
            for (int j = i; j <= end; j++) {
                int cj = s[j] - 'a';
                if (first[cj] < i) { ok = false; break; }
                end = max(end, last[cj]);
            }
            if (ok) validIntervals.push_back({i, end});
        }
        vector<pair<int,int>> result;
        vector<pair<pair<int,int>, bool>> stk;
        for (auto& iv : validIntervals) {
            while (!stk.empty() && iv.first > stk.back().first.second) {
                auto top = stk.back();
                stk.pop_back();
                if (!top.second) result.push_back(top.first);
            }
            if (!stk.empty()) stk.back().second = true;
            stk.push_back({iv, false});
        }
        while (!stk.empty()) {
            auto top = stk.back();
            stk.pop_back();
            if (!top.second) result.push_back(top.first);
        }
        vector<string> ans;
        for (auto& p : result) ans.push_back(s.substr(p.first, p.second - p.first + 1));
        return ans;
    }
};