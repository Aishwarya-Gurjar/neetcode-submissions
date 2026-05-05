class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<bool>visited(n,false);
       vector<vector<int>>adj(n);

       for(int i=0;i<edges.size();i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
       }

       bool res = bfs(adj, 0, visited);
       if(!res) return false;
       for(int i=0;i<n;i++){
        if(!visited[i]) return false;
       }
       return true;
    }

    // 0, 1->t

    bool bfs(vector<vector<int>>&adj, int node, vector<bool>&visited) {
        queue<int>q;
        q.push(node); // 0
        while(!q.empty()) {
            int front = q.front(); //0
            q.pop();
            if(visited[front])  return false; 
            for(int i: adj[front]) {
                if(!visited[i])  q.push(i);// 4
            }
            visited[front]=true; 
        }
        return true;
    }
};
