#include <bits/stdc++.h>
using namespace std;


int getMinDiff(int arr[], int n, int k)
{
    // There should be at least two elements
    if (n <= 1)
        return 0;

    // Sort array in increasing order
    sort(arr, arr+n);

    // Initialize maximum and minimum
    int maxe = arr[n-1];
    int mine = arr[0];

    if(k >= maxe - mine)
    {
        for (int i=0; i<n; i++)
            arr[i] += k; // Subtract would also work
        return (maxe - mine);
    }


    arr[0]   += k;
    arr[n-1] -= k;

    // Initialize mac and min of modified array (only
    // two elements have been finalized)
    int new_max = max(arr[0], arr[n-1]);
    int new_min = min(arr[0], arr[n-1]);

    // Finalize middle n-2 elements
    for (int j=1; j<n-1; j++)
    {
        // If current element is less than min of
        // modified array, add k.
        if (arr[j] < new_min)
            arr[j] += k;

        // If current element is more than max of
        // modified array, subtract k.
        else if (arr[j] > new_max)
            arr[j] -= k;

        // arr[j] is between new_min and new_max

        // If arr[j] is closer to new_max, subtract k
        else if ((arr[j] - new_min) > (new_max - arr[j]))
            arr[j] -= k;

        // Else add k
        else
            arr[j] += k;

        // Update new_max and new_min if required
        new_max = max(arr[j], new_max);
        new_min = min(arr[j], new_min);
    }

    // Returns difference between new_max and new_min
    return (new_max - new_min);
}

// Driver function to test the above function
int main()
{
    int arr[] = {1, 15, 10} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    int res = getMinDiff(arr, n, k);

    cout << "Modified array is \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\nMaximum difference is " << res;
    return 0;
}
