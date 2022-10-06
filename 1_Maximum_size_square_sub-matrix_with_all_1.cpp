/*
    link: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0

    video: https://www.youtube.com/watch?v=UagRoA3C5VQ&ab_channel=Pepcoding
*/

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        int mx = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {

                /* here if any of the neighbour is 0 then size will be 1(itself) as we have to find matrix with all 1.
                    hence for that reason we have to take min of all the neighbour square in mat.
                 */
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
                // if current ele is 0 then it's any sub-square matrix won't counted.
                //else dp[i][j] = 0; //no need to write this line as it was already settled in memset
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //