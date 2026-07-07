class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";
            int cnt = 1;

            for (int j = 1; j < ans.size(); j++) {
                if (ans[j] == ans[j - 1]) {
                    cnt++;
                } else {
                    temp += to_string(cnt);
                    temp += ans[j - 1];
                    cnt = 1;
                }
            }

            // Add the last group
            temp += to_string(cnt);
            temp += ans.back();

            ans = temp;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna