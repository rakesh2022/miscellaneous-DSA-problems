
//  https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

const int mod = 1e9+7;

class Solution {
    vector<vector<vector<int>>> dp;
    
    int NumberOfPaths (int i, int j, int modulus_val, const vector<vector<int>>& grid, const int K) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i >= m || j >= n) return 0;
        if (i == m-1 && j == n-1) return (grid[i][j] % K == modulus_val);
        
        int &ans = dp[i][j][modulus_val];
        if (ans != -1) return ans;
        
        int remainder = (modulus_val - (grid[i][j] % K) + K) % K;
        ans = (NumberOfPaths (i+1, j, remainder, grid, K) + NumberOfPaths (i, j+1, remainder, grid, K)) % mod;
        return ans;
    }
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.clear();
        int m = grid.size();
        int n = grid[0].size();
        
        dp.resize (m, vector<vector<int>>(n, vector<int>(k, -1)));
        return NumberOfPaths (0, 0, 0, grid, k);
    }
};