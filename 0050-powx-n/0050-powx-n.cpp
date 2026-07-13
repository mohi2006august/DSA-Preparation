class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        double ans = 1.0;

        while (power > 0) {
            if (power % 2 == 1)
                ans *= x;

            x *= x;
            power /= 2;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna