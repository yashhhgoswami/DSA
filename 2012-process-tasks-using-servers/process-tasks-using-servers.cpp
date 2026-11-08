class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeServers;
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> busy;

        for (int i = 0; i < n; i++) freeServers.push({servers[i], i});

        vector<int> ans(m);
        long long time = 0;

        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);
            if (freeServers.empty()) {
                time = max(time, get<0>(busy.top()));
            }
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, w, idx] = busy.top();
                busy.pop();
                freeServers.push({w, idx});
            }

            auto [w, idx] = freeServers.top();
            freeServers.pop();
            ans[j] = idx;
            busy.push({time + tasks[j], w, idx});
        }

        return ans;
    }
};