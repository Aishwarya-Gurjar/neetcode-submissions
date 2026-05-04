class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int>visited;
        vector<vector<int>>adj(n);
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                count++;
                bfs(visited, adj, i);
            }
        }
        return count;
    }

    void bfs(unordered_set<int>&visited, vector<vector<int>>&adj, int node){
        if(visited.count(node)) return;
        queue<int>q;
        q.push(node);
        visited.insert(node);

        while(!q.empty()){
            int tp = q.front();
            q.pop();
            for(int k : adj[tp]){
                if(!visited.count(k)){
                    q.push(k);
                    visited.insert(k);
                }
            }
        }
        return;
    }
};
