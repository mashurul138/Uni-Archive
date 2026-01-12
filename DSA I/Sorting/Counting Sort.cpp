#include <iostream>

using namespace std;

int main()
{
    int arr[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxi = arr[0];

    for (int i = 1; i < n; i++)
        maxi = max(maxi, arr[i]);

    int count[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxi; i++)
        count[i] += count[i - 1];

    int arrSorted[n];
    for (int i = n - 1; i >= 0; i--)
        arrSorted[--count[arr[i]]] = arr[i];

    for (int i : arrSorted)
        cout << i << " ";

    return 0;
}