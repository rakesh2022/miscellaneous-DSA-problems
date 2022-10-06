/*
   variation of 0/1 knapsack.

   link: https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

   all different variation are in link.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
    // base case when all elements are removed
    if (i >= j)
        return 0;

    // if condition is satisfied, no more
    // removals are required
    else if ((a[j] - a[i]) <= k)
        return 0;

    // if the state has already been visited
    else if (dp[i][j] != -1)
        return dp[i][j];

    // when Amax-Amin>d
    else if ((a[j] - a[i]) > k)
    {

        // minimum is taken of the removal
        // of minimum element or removal
        // of the maximum element
        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}

// To sort the array and return the answer
int removals(int a[], int n, int k)
{
    // sort the array
    sort(a, a + n);

    // fill all stated with -1
    // when only one element
    memset(dp, -1, sizeof(dp));
    if (n == 1)
        return 0;
    else
        return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
/*
    Time Complexity :O(n^2)
    Auxiliary Space: O(n^2)
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// C++ program for the above approach
class Solution
{
public:
    int removals(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        int n = a.size();
        for (int i = 0; i < a.size(); i++)
        {
            int end = upper_bound(a.begin() + i, a.end(), a[i] + k) - a.begin();
            ans = min(ans, n - end + i);
        }
        return ans;
    }
};
/*
    Time Complexity :O(n log(n))
    Auxiliary Space: O(n)
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// To sort the array and return the answer
int removals(int arr[], int n, int k)
{

    // sort the array
    sort(arr, arr + n);
    int dp[n];

    // fill all stated with -1
    // when only one element
    for (int i = 0; i < n; i++)
        dp[i] = -1;

    // as dp[0] = 0 (base case) so min
    // no of elements to be removed are
    // n-1 elements
    int ans = n - 1;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = i;
        int j = dp[i - 1];
        while (j != i && arr[i] - arr[j] > k)
        {
            j++;
        }
        dp[i] = min(dp[i], j);
        ans = min(ans, (n - (i - j + 1)));
    }
    return ans;
}

// Driver code
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
/*
    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/

// ----------------------------------------------------------------------------------------------------------------------- //