class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, int n, int k, vector<int>& curr) {
        // Combination completed
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);

            backtrack(i + 1, n, k, curr);

            curr.pop_back(); // undo choice
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(1, n, k, curr);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna