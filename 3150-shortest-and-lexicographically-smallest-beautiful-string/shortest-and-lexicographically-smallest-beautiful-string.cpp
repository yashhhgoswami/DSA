class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        int bestLen = INT_MAX;
        string best = "";
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            while (ones == k) {
                int len = right - left + 1;
                if (len < bestLen) {
                    bestLen = len;
                    best = s.substr(left, len);
                } else if (len == bestLen) {
                    string cand = s.substr(left, len);
                    if (cand < best) best = cand;
                }
                if (s[left] == '1') ones--;
                left++;
            }
        }
        return best;
    }
};