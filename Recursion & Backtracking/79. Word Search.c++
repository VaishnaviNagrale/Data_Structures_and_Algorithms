class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    bool dfs(int r, int c, int idx, vector<vector<char>>& board, string word) {
        if (idx >= word.size())
            return true;

        if (r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[idx])
            return false;

        char temp = board[r][c];
        board[r][c] = '*';

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (dfs(nrow, ncol, idx + 1, board, word))
                return true;
        }

        board[r][c] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
