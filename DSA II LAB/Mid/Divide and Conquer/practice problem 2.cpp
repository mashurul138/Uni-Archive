#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int vowelCount(string s, int low, int high)
{
    if (low == high)
    {
        if (isVowel(s[low]))
            return 1;
        return 0;
    }
    int mid = (low + high) / 2;
    int l = vowelCount(s, low, mid);
    int r = vowelCount(s, mid + 1, high);
    return l + r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    cout << vowelCount(str, 0, str.size() - 1);
    return 0;
}