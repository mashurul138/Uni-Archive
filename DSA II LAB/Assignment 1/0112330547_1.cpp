#include <bits/stdc++.h>

using namespace std;

vector<int> LPP(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        if (arr[l] > 0)
            return {l};
        else
            return {};
    }
    int mid = (l + r) / 2;
    vector<int> left = LPP(arr, l, mid);
    vector<int> right = LPP(arr, mid + 1, r);
    int lcnt = 0, i = mid;
    while (i >= l && arr[i] > 0)
    {
        lcnt++;
        i--;
    }
    int rcnt = 0, j = mid + 1;
    while (j <= r && arr[j] > 0)
    {
        rcnt++;
        j++;
    }
    int crossLen = lcnt + rcnt;
    vector<int> cross;
    if (crossLen > 0)
    {
        for (int k = mid - lcnt + 1; k <= mid + rcnt; k++)
            cross.push_back(k);
    }
    if (left.size() >= right.size() && left.size() >= cross.size())
        return left;
    if (right.size() >= left.size() && right.size() >= cross.size())
        return right;
    return cross;
}

int main()
{
    vector<int> profits(10);
    for (int i = 0; i < 10; i++)
        cin >> profits[i];
    vector<int> ans = LPP(profits, 0, profits.size() - 1);
    cout << "Longest profit period " << ans.size() << endl;
    if (!ans.empty())
    {
        cout << "Month range: ";
        for (int i = 0; i < ans.size(); i++)
            cout << "M" << (ans[i] + 1) << " ";
        cout << endl;
    }
    return 0;
}
