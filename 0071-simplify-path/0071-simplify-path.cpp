class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // Ignore
                }
                else if (curr == "..") {
                    if (!st.empty())
                        st.pop_back();
                }
                else {
                    st.push_back(curr);
                }

                curr = "";
            }
            else {
                curr += path[i];
            }
        }

        if (st.empty())
            return "/";

        string ans;
        for (string dir : st)
            ans += "/" + dir;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna