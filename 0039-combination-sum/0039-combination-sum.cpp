class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Take current candidate
        path.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index);
        path.pop_back();

        // Skip current candidate
        dfs(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna