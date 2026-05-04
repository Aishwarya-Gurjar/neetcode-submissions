class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>eta(n+1, INT_MAX);
        vector<bool>visited(n+1, false);
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>indegree(n+1, 0);
        for(int i=0;i<times.size();i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
            indegree[times[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(indegree[i]==0 && i!=k)  return -1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0, k});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            eta[top.second] = min(eta[top.second], top.first);
            if(visited[top.second]) continue;
            for(auto edges : adj[top.second]) {
                int time = edges.second;
                int node = edges.first;
                pq.push({time + top.first, node});
            }
            visited[top.second] = true;
        }

        int result = INT_MAX;
        result = *max_element(eta.begin()+1, eta.end());

        return result==INT_MAX ? -1 : result;
    }
};
