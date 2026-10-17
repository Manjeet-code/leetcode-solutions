class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][2] = Buy state
        // dp[i][1] = Sell state
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            // Buy: buy today or skip
            dp[i][2] = max(-prices[i] + dp[i + 1][1],
                           dp[i + 1][2]);

            // Sell: sell today or skip
            dp[i][1] = max(prices[i],
                           dp[i + 1][1]);
        }

        return dp[0][2];
    }
};