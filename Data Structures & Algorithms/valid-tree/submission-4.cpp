class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n, vector<int>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_set<int>visited;
        queue<pair<int,int>>q;
        q.push({0,-1});
        visited.insert(0);

        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            for(int neigh : adj[node]){
                if(neigh == parent){
                    continue;
                }
                if(visited.count(neigh)){
                    return false;
                }
                visited.insert(neigh);
                q.push({neigh, node});
            }
        }

        return visited.size()==n;
    }
};
