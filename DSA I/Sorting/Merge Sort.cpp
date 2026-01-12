#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> merged(high - low);
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            merged[k++] = arr[i++];
        else
            merged[k++] = arr[j++];
    }

    if (j > high)
    {
        for (int p = i; p <= mid; p++)
            merged[k++] = arr[p];
    }
    else
    {
        for (int p = j; p <= high; p++)
            merged[k++] = arr[p];
    }
    for (int p = low; p <= high; p++)
        arr[p] = merged[p];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    vector<int> arr = {50, 32, 12, 50, 45, 99, 12, 10, 4, 93};
    mergeSort(arr, 0, arr.size() - 1);
    for (int a : arr)
        cout << a << " ";
    return 0;
}