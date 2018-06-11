//
// Created by 刘敬 on 18/5/31.
//

#include "add.h"

int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
    for (int i = 1; i < m; i++)
        sum[i][0] = sum[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++)
        sum[0][j] = sum[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    return sum[m - 1][n - 1];

}



void _tmain(){
    vector<vector<int>> grid = {{1,1,1},{2,2,2},{3,3,3}};
    minPathSum(grid);
}