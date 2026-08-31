class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx = -1, lastIdx = -1, prevCritIdx = -1;
        int minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        while (curr->next) {
            int pv = prev->val, cv = curr->val, nv = curr->next->val;
            bool isCritical = (cv > pv && cv > nv) || (cv < pv && cv < nv);
            if (isCritical) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - prevCritIdx);
                }
                prevCritIdx = idx;
                lastIdx = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if (firstIdx == -1 || firstIdx == lastIdx) {
            return {-1, -1};
        }
        int maxDist = lastIdx - firstIdx;
        return {minDist, maxDist};
    }
};