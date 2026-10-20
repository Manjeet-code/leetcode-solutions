class Solution {
public:
    int fun(vector<int>& c, int i, int j,
            vector<vector<int>>& dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = c[j + 1] - c[i - 1];

            int r = cost
                  + fun(c, i, k - 1, dp)
                  + fun(c, k + 1, j, dp);

            res = min(res, r);
        }

        return dp[i][j] = res;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<int> c = cuts;

        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());

        int s = cuts.size();

        vector<vector<int>> dp(s + 2, vector<int>(s + 2, -1));

        return fun(c, 1, s, dp);
    }
};