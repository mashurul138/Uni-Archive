#include <bits/stdc++.h>

using namespace std;

vector<int> MTT(vector<int> &t, int l, int r)
{
    if (r - l + 1 <= 3)
    {
        vector<int> res;
        for (int i = l; i <= r; i++)
            res.push_back(i);
        return res;
    }
    int mid = (l + r) / 2;
    vector<int> left = MTT(t, l, mid);
    vector<int> right = MTT(t, mid + 1, r);
    int crossSum = INT_MIN;
    vector<int> cross;
    for (int i = mid - 1; i <= mid; i++)
    {
        if (i >= l && i + 2 <= r)
        {
            int sum = t[i] + t[i + 1] + t[i + 2];
            if (sum > crossSum)
            {
                crossSum = sum;
                cross = {i, i + 1, i + 2};
            }
        }
    }
    int leftSum = 0, rightSum = 0;
    for (int idx : left)
        leftSum += t[idx];
    for (int idx : right)
        rightSum += t[idx];
    if (leftSum >= rightSum && leftSum >= crossSum)
        return left;
    if (rightSum >= leftSum && rightSum >= crossSum)
        return right;
    return cross;
}

int main()
{
    int n;
    cin >> n;
    vector<int> temps(n);
    for (int i = 0; i < n; i++)
        cin >> temps[i];
    vector<int> ans = MTT(temps, 0, n - 1);
    if (!ans.empty())
    {
        cout << "Maximum 3-day temperature : ";
        for (int i = 0; i < ans.size(); i++)
            cout << temps[ans[i]] << " ";
        cout << endl;
    }
    return 0;
}
