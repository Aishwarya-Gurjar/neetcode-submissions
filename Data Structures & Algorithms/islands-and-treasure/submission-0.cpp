class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==0)   q.push({i,j});
            }
        }
        vector<pair<int,int>>offset = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();
            for(auto k : offset){
                if(isValidPlace(top, k, m, n, grid)){
                    q.push({top.first+k.first, top.second+k.second});
                    grid[top.first+k.first][top.second+k.second] = 1+ grid[top.first][top.second];
                }
            }
        }

        return;
    }

    bool isValidPlace(pair<int,int>&index, pair<int,int>&offset, int r, int c, vector<vector<int>>& grid) {
        if(index.first+offset.first < 0 || index.first+offset.first >=r ||
            index.second+offset.second < 0 || index.second+offset.second >=c) return false;

        return grid[index.first+offset.first][index.second+offset.second] == INT_MAX;
    }
};
