other arraya questions
//   https://github.com/viren-sureja/Love-Babbar-450/blob/3d4414a88d921823d2d79df61b485be6d475c8af/01_array/09_minimize_the_height.cpp
//  https://github.com/viren-sureja/Love-Babbar-450/blob/3d4414a88d921823d2d79df61b485be6d475c8af/01_array/10_min_jumps_to_reach_end.cpp



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
