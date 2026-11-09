class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy; // (end time, server)
        vector<int> cnt(k, 0);

        for (int i = 0; i < n; i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }
            if (freeServers.empty()) continue;

            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin();

            int id = *it;
            freeServers.erase(it);
            cnt[id]++;
            busy.push({arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};