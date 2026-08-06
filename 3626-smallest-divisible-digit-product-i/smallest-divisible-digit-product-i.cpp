class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n; ; x++) {
            long long product = 1;
            int temp = x;
            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }
            if (product % t == 0) {
                return x;
            }
        }
    }
};