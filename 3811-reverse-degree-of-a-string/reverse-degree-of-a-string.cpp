class Solution {
public:
    int reverseDegree(string s) {
        long long sum = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int reversedPos = 26 - (s[i] - 'a');
            int stringPos = i + 1;
            sum += (long long)reversedPos * stringPos;
        }
        return (int)sum;
    }
};