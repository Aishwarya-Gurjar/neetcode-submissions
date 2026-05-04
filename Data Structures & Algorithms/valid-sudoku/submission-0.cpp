class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9];
        unordered_set<char>col[9];
        unordered_set<char>box[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')    continue;

                int boxNum = (i/3)*3 + (j/3);
                if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || box[boxNum].count(board[i][j])) return false;

                row[i].insert(board[i][j]);

                col[j].insert(board[i][j]);

                box[boxNum].insert(board[i][j]);
            }
        }
        return true;
    }
};
