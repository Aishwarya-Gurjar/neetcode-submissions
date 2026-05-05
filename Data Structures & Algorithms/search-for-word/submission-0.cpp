class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                vector<vector<bool>>visited(m,vector<bool>(n,false));
                if(board[i][j]==word[0] && isWordPresent(board,i,j,word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isWordPresent(vector<vector<char>>& board, int r, int c, string word, int index, vector<vector<bool>>&visited) {
        if(index==word.size())  return true;
        if(r>=m || r<0 || c>=n || c<0 || visited[r][c] || board[r][c]!=word[index]) return false;

        visited[r][c] = true;
        vector<int> dir_x = {-1, 0, 1, 0};
        vector<int> dir_y = {0, 1, 0, -1};

        for(int i=0;i<4;i++) {
            bool isFound = isWordPresent(board, r+dir_x[i], c+dir_y[i], word, index+1, visited);
            if(isFound) return true;

        }
        visited[r][c] = false;
        return false;
    }
};
