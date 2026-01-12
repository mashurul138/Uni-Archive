#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    int data;
    struct Node *next = nullptr;
    Node(int x)
    {
        data = x;
    }
};

node *head, *tail;

void insert(int x)
{
    node *temp = new Node(x);
    if (head == nullptr)
    {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}

void display()
{
    node *cur = head;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

bool isPalindrome()
{
    if (head == nullptr || head->next == nullptr)
        return true;

    node *cur = head;
    stack<int> st;
    while (cur)
    {
        st.push(cur->data);
        cur = cur->next;
    }

    node *temp = head;
    while (temp)
    {
        if (temp->data != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(1);
    if (isPalindrome())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}