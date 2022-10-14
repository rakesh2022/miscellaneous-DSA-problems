// Given a single array and every element of that array contains the efficiency of a worker, we have to assign work to the worker, and we have to give work to workers in pair.
// There are an odd number of elements in the array. We have to pair all the elements of the array in such a way that the sum of the absolute difference of all the pairs that we have formed should be minimum.

// E.g.
// Input - arr={4,2,1,8,9}
// Output - 2

// Explanation - The pair will be (1,2),(8,9) and the sum of there absolute difference -> |1-2|+|8-9|=1+1=2


solution:

int arr[] = {4,2,1,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    int l = 0;
    int r = 0;
    int mul = -1;
    for(int i = 1; i < n; i++){
      r += mul * arr[i];
      mul *= -1;      
    }
    int ans = l + r;
    mul = 1;
    l = -arr[0];
    for(int i = 1; i < n; i++){
      r += mul * arr[i];
      ans = min(ans, l + r);
      cout << "ans: " << ans << endl;
      l += mul*arr[i];
      mul *= -1;
    }
    cout << "ans: " << ans << endl;