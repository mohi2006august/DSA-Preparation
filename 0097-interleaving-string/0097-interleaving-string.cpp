class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size())
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // Fill first column
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // Fill first row
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill remaining table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                bool takeS1 = dp[i - 1][j] &&
                              (s1[i - 1] == s3[i + j - 1]);

                bool takeS2 = dp[i][j - 1] &&
                              (s2[j - 1] == s3[i + j - 1]);

                dp[i][j] = takeS1 || takeS2;
            }
        }

        return dp[n][m];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna