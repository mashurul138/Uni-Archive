#include <bits/stdc++.h>

using namespace std;

vector<int> CPP(vector<int> arr, int low, int mid, int high)
{
    int l = mid;
    while (l >= low && arr[l] > 0)
        l--;
    int r = mid + 1;
    while (arr[r] > 0 && r <= high)
        r++;
    vector<int> cross;
    for (int i = l + 1; i < r; i++)
        cross.push_back(i);
    return cross;
}

vector<int> LPP(vector<int> arr, int low, int high)
{
    if (low == high)
    {
        if (arr[low] > 0)
            return {low};
        else
            return {};
    }
    int mid = (low + high) / 2;
    vector<int> left = LPP(arr, low, mid);
    vector<int> right = LPP(arr, mid + 1, high);
    vector<int> cross = CPP(arr, low, mid, high);

    if (left.size() >= right.size() && left.size() >= cross.size())
        return left;
    if (right.size() >= left.size() && right.size() >= cross.size())
        return right;
    return cross;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> profits(10);
    for (int i = 0; i < 10; i++)
        cin >> profits[i];
    vector<int> ans = LPP(profits, 0, profits.size() - 1);
    cout << ans.size() << endl;
    if (!ans.empty())
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    return 0;
}