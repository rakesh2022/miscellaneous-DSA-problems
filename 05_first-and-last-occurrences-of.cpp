/*
    link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
*/

// -----

vector<int> find(int arr[], int n, int x)
{
    int f = lower_bound(arr, arr + n, x) - arr;
    int l = upper_bound(arr, arr + n, x) - arr;
    if (l == f)
        return {-1, -1};
    return {f, l - 1};
}