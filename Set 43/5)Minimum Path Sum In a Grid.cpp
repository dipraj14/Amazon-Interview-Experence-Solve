// https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;
// 0, 0 --> n-1, m-1
// int helper(int i, int j, vector<vector<int>>& grid, int n, int m , vector<vector<int>> &dp){
//         if( i == n - 1 && j == m - 1){
//             return grid[i][j];
//         }
//         if(i >= n or j >= m) return INT_MAX;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down =grid[i][j] + helper(i + 1, j, grid, n, m ,dp);
//         int right =grid[i][j] + helper(i, j + 1, grid, n, m ,dp);
        
//        return dp[i][j] =  min(down, right);
// }
// int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n + 1 , (vector<int> (m + 1 , -1)));
//        return helper(0, 0 , grid, n , m, dp);
// }
// int main(){
//     int n, m ;
//     cin >> n >> m;
//     vector<vector<int>>grid(n, vector<int>(m));

//     for(int i=0; i<n; i++){
//         for(int j = 0; j < m ; j++){
//             cin >> grid[i][j];
//         }
//     }

//     cout << minPathSum(grid);
// }

// n - 1, m - 1 = 0 , 0

int helper(int i, int j, vector<vector<int>>& grid, int n, int m , vector<vector<int>> &dp){
        if( i == 0 && j == 0){
            return grid[i][j];
        }
        if(i < 0 or j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + helper(i - 1 , j, grid, n, m ,dp);
        int left = grid[i][j] + helper(i, j - 1, grid, n, m ,dp);
        
       return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1 , (vector<int> (m + 1 , -1)));
       return helper(n - 1, m - 1 , grid, n , m, dp);
}
int main(){
    int n, m ;
    cin >> n >> m;
    vector<vector<int>>grid(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j = 0; j < m ; j++){
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid);
}