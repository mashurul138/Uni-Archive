#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int i, int j, int k)
{
    if (n == 1)
        cout << i << " --> " << k << endl;
    else
    {
        hanoi(n - 1, i, k, j);
        cout << i << " --> " << k << endl;
        hanoi(n - 1, j, i, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);

    return 0;
}