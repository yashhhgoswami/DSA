class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) return 0;
        if (n == 2) return -1;

        int l = 0, r = n - 1;
        while (s[l] == t[l]) l++;
        while (s[r] == t[r]) r--;
        if (!(l == 0 && r == n - 1)) return 1;

        char mn = t[0], mx = t[n - 1];
        bool minInPrefix = false, maxInSuffix = false;
        for (int i = 0; i < n - 1; i++) if (s[i] == mn) { minInPrefix = true; break; }
        for (int i = 1; i < n; i++) if (s[i] == mx) { maxInSuffix = true; break; }

        return (minInPrefix || maxInSuffix) ? 2 : 3;
    }
};