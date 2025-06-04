class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int from_top = INT_MAX;
                int from_top_left = INT_MAX;

                if (j < triangle[i - 1].size())
                    from_top = dp[i - 1][j];

                if (j - 1 >= 0)
                    from_top_left = dp[i - 1][j - 1];

                dp[i][j] = triangle[i][j] + min(from_top, from_top_left);
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < triangle[n - 1].size(); j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};
