#include <bits/stdc++.h>

using namespace std;

int countEven(vector<int> arr, int low, int high)
{
    if (low == high)
    {
        if (arr[low] & 1)
            return 0;
        return 1;
    }
    int mid = (low + high) / 2;
    int left = countEven(arr, low, mid);
    int right = countEven(arr, mid + 1, high);
    return left + right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << countEven(nums, 0, nums.size() - 1);
    return 0;
}