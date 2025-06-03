class Solution {
public:
    // int solve(int i, int j , int n , int m,vector<vector<int>>& matrix,vector<vector<int>> &dp){
    //     if (j < 0 || j >= m) return INT_MAX;
        
    //     if (i == n - 1) return matrix[i][j];
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int down = solve(i+1,j,n,m,matrix,dp);
    //     int bottom_left = solve(i+1,j-1,n,m,matrix,dp);
    //     int bottom_right = solve(i+1,j+1,n,m,matrix,dp);
    //     return dp[i][j] = matrix[i][j] + min({down,bottom_left,bottom_right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i<m;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiagonal = matrix[i][j];
                int rightDiagonal = matrix[i][j];
                if(j-1 >= 0){
                    leftDiagonal += dp[i-1][j-1];
                }else{
                    leftDiagonal += 1e9;
                }

                if(j+1 <m){
                    rightDiagonal+= dp[i-1][j+1];
                }else{
                    rightDiagonal += 1e9;
                }
                dp[i][j] = min({up,leftDiagonal,rightDiagonal});
            }
        }

        int mini = INT_MAX;

        for(int i = 0; i<m;i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;

    }
};