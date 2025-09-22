#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>> &arr, int left, int mid, int right, vector<int> &result)
{
    vector<pair<int, int>> temp;
    int i = left, j = mid + 1;
    int rightCount = 0; // how many elements from right half have been placed before arr[i]

    while (i <= mid && j <= right)
    {
        if (arr[i].first <= arr[j].first)
        {
            result[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            rightCount++;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        result[arr[i].second] += rightCount;
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<pair<int, int>> &arr, int left, int right, vector<int> &result)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, result);
    mergeSort(arr, mid + 1, right, result);
    merge(arr, left, mid, right, result);
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 0);
    vector<pair<int, int>> arr; // pair of (value, index)

    for (int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }

    mergeSort(arr, 0, n - 1, result);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> result = countSmaller(nums);

    cout << "Result: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
