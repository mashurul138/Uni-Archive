#include <bits/stdc++.h>

using namespace std;

vector<int> CTT(vector<int> arr, int low, int mid, int high)
{
    if (high - low + 1 >= 3)
        return {arr[mid - 1], arr[mid], arr[mid + 1], (arr[mid - 1] + arr[mid] + arr[mid + 1])};
    return {};
}

vector<int> HTT(vector<int> arr, int low, int high)
{
    if (high - low + 1 <= 3)
    {
        vector<int> temp;
        int sum = 0;
        for (int i = low; i < high; i++)
        {
            temp.push_back(arr[i]);
            sum += arr[i];
        }
        temp.push_back(sum);
        return temp;
    }
    int mid = (low + high) / 2;
    vector<int> left = HTT(arr, low, mid);
    vector<int> right = HTT(arr, mid + 1, high);
    vector<int> cross = CTT(arr, low, mid, high);
    if (!cross.empty())
    {
        if (left[left.size() - 1] > right[right.size() - 1] && left[left.size() - 1] > cross[cross.size() - 1])
            return left;
        if (right[right.size() - 1] > left[left.size() - 1] && right[right.size() - 1] > cross[cross.size() - 1])
            return right;
        return cross;
    }
    else
    {
        if (left[left.size() - 1] > right[right.size() - 1])
            return left;
        return right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++)
        cin >> temperatures[i];
    vector<int> ans = HTT(temperatures, 0, temperatures.size() - 1);
    for(int i : ans)
        cout << i << endl;
    return 0;
}