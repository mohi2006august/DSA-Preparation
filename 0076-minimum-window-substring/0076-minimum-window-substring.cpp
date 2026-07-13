class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> need;
        for (char c : t)
            need[c]++;

        unordered_map<char, int> window;

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];
            window[c]++;

            // Character requirement satisfied
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try shrinking the window
            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    formed--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna