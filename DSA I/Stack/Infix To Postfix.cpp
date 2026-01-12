#include <bits/stdc++.h>

using namespace std;

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

bool opening(char ch)
{
    return ch == '(' || ch == '{' || ch == '[';
}

bool closing(char ch)
{
    return ch == ')' || ch == '}' || ch == ']';
}

string infix_to_postfix(string s)
{
    int n = s.size(), i = 0;
    stack<int> st;
    string ans = "";
    while (i < n)
    {
        if (isalnum(s[i]))
            ans += s[i];
        else if (opening(s[i]))
            st.push(s[i]);
        else if (closing(s[i]))
        {
            while (!st.empty() && !opening(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s = "a+b-(c*d/e-f)^c";
    cout << infix_to_postfix(s);
}
