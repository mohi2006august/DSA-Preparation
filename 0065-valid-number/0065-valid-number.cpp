class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
            }
            else if (c == '+' || c == '-') {
                // Sign is allowed only at the beginning
                // or immediately after e/E.
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Only one dot and not after exponent.
                if (dot || exp)
                    return false;
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                // Only one exponent and must come after a digit.
                if (exp || !digit)
                    return false;
                exp = true;
                digit = false; // Need at least one digit after e/E.
            }
            else {
                return false;
            }
        }

        return digit;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna