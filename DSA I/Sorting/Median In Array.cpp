// Find the median from an array.

// input
// a =[5,2,1,4,7]
// a =[11,9,17,15]

// output
//  4
//  13

#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int a[] = {5, 2, 1, 4, 7};
    int b[] = {11, 9, 17, 15};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    insertionSort(a, n);
    selectionSort(b, m);
    if (n % 2 == 1)
    {
        cout << a[n / 2] << endl;
    }
    else
    {
        cout << (a[n / 2] + a[(n / 2) + 1]) / 2 << endl;
    }
    if (m % 2 == 1)
    {
        cout << b[(m / 2) - 1] << endl;
    }
    else
    {
        cout << (b[(m / 2) - 1] + b[(m / 2)]) / 2 << endl;
    }
}