#include <bits/stdc++.h>

using namespace std;

int value(char ch)
{
    if (ch == 'a' || ch == 'c' || ch == 'f')
        return 1;
    else if (ch == 'b' || ch == 'd' || ch == 'e')
        return 2;
    return (ch - '0');
}

int postfix_evaluasion(string s)
{
    int i = 0, n = s.size();
    stack<char> st;
    while (i < n)
    {
        if (isalnum(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            int b = value(st.top());
            st.pop();
            int a = value(st.top());
            st.pop();
            int temp = 0;
            if (s[i] == '+')
                temp = a + b;
            else if (s[i] == '-')
                temp = a - b;
            else if (s[i] == '*')
                temp = a * b;
            else if (s[i] == '/')
                temp = a / b;
            else if (s[i] == '^')
                temp = pow(a, b);

            char x = temp + '0';
            st.push(x);
        }
        i++;
    }
    return st.top() - '0';
}

int main()
{
    string s = "ab+cd*e/f-c^-";
    cout << postfix_evaluasion(s);
}
