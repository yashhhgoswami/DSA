class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suf(m + 1, -1);
        suf[m] = n;
        {
            int j = m - 1;
            for (int i = n - 1; i >= 0 && j >= 0; --i) {
                if (word1[i] == word2[j]) {
                    suf[j] = i;
                    --j;
                }
            }
        }
        vector<int> res;
        res.reserve(m);
        int jj = 0;
        bool changed = false;       
        for (int i = 0; i < n && jj < m; ++i) {
            if (word1[i] == word2[jj]) {
                res.push_back(i);
                ++jj;
            } else if (!changed) {
                int need = jj + 1;
                if (suf[need] > i) {
                    res.push_back(i);
                    ++jj;
                    changed = true;
                }
            }
        }        
        if (jj == m) return res;
        return {};
    }
};