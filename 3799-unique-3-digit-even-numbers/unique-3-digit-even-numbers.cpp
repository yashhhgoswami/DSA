class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) freq[d]++;
        int count = 0;
        for (int num = 100; num <= 998; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            int need[10] = {0};
            need[hundreds]++;
            need[tens]++;
            need[units]++;
            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (need[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }
        return count;
    }
};