class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Entire word found
        if (index == word.size())
            return true;

        // Boundary and character check
        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[index])
            return false;

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna