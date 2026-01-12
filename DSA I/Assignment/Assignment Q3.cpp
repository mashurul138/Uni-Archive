#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    char data;
    int count = 0;
    Node *next = nullptr;
};

node *head = nullptr;
node *tail = nullptr;

void createNode()
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        node *temp = new node();
        temp->data = c;
        if (head == nullptr)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

void display()
{
    node *cur = head;
    while (cur)
    {
        cout << cur->data << " : " << cur->count << endl;
        cur = cur->next;
    }
}

int main()
{
    createNode();
    cout << "Enter a String: " << endl;
    string s;
    cin >> s;
    for (char c : s)
    {
        c = tolower(c);
        if (c >= 'a' && c <= 'z')
        {
            node *cur = head;
            while (cur->data != c)
            {
                cur = cur->next;
            }
            cur->count++;
        }
    }
    display();
}