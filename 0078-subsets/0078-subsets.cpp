class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int>& nums, vector<int>& curr) {
        // Store current subset
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            // Choose
            curr.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, curr);

            // Undo choice
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(0, nums, curr);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna