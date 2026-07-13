class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        for (int i = 1; i < n; i++)
            fact *= i;

        for (int i = 1; i <= n; i++)
            numbers.push_back(i);

        k--; // Convert to 0-based indexing

        string ans;

        while (true) {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + (k / fact));

            if (numbers.empty())
                break;

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna