// bottom up is not added
// requires multiple revisions
// hard

class Solution {
public:
    int t[71][71][71];
    int solve(vector<vector<int>>& grid, int row, int col_1, int col_2){
        if(row >= grid.size()) return 0;
        int cherry = grid[row][col_1];
        if(col_1 != col_2){
            cherry += grid[row][col_2];
        }

        if(t[row][col_1][col_2]!=-1){
            return t[row][col_1][col_2];
        }
        int ans = 0;
        for(int i = -1; i<=1;i++){
            for(int j = -1; j<=1; j++){
             int new_row = row+1;
             int new_col_1 = col_1 + i;
             int new_col_2 = col_2 + j;
             if(new_col_1 >= 0 && new_col_2 >= 0 && new_col_1 < grid[0].size() && new_col_2 < grid[0].size() )
                 ans = max(ans, solve(grid,new_row, new_col_1,new_col_2));
            }
        }

        return t[row][col_1][col_2] =  ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, m-1);
    }
};
