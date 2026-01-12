#include <bits/stdc++.h>

using namespace std;

int partitionFunction(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (i < j)
    {
        while (arr[i] < pivot && i < j)
            i++;
        while (arr[j] > pivot && i < j)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    return j;
}

void qucikSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = partitionFunction(arr, low, high);
        qucikSort(arr, low, partition - 1);
        qucikSort(arr, partition + 1, high);
    }
}

int main()
{
    int arr[] = {18, 23, 56, 26, 235, 6543, 12423, 53543, 89, 37, 28, 48};
    int n = sizeof(arr) / sizeof(arr[0]);
    qucikSort(arr, 0, n - 1);

    for (int a : arr)
        cout << a << " ";
    return 0;
}