class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char ch : s) cnt[ch - 'a']++;
        vector<array<int,26>> availAfter(n + 1);
        for (int i = 0; i < 26; i++) availAfter[0][i] = cnt[i];
        int failIndex = n;
        for (int i = 0; i < n; i++) {
            availAfter[i+1] = availAfter[i];
            int c = target[i] - 'a';
            if (availAfter[i][c] > 0) {
                availAfter[i+1][c] -= 1;
            } else {
                failIndex = i;
                break;
            }
        }
        int U = min(failIndex, n - 1);
        for (int j = U; j >= 0; j--) {
            array<int,26>& avail = availAfter[j];
            int tc = target[j] - 'a';
            int g = -1;
            for (int c = tc + 1; c < 26; c++) {
                if (avail[c] > 0) { g = c; break; }
            }
            if (g == -1) continue; 
            string res = target.substr(0, j);
            res += char('a' + g);
            array<int,26> remain = avail;
            remain[g]--;
            for (int c = 0; c < 26; c++)
                for (int k = 0; k < remain[c]; k++) res += char('a' + c);
            return res;
        }
        return "";
    }
};