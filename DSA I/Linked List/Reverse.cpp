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

void reverseLL()
{
    node *prev = nullptr, *cur = head;
    while (cur)
    {
        node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void createList(vector<int> arr)
{
    node *circleNode, *temp;
    for (int i = 0; i < arr.size(); i++)
    {
        temp = new Node(arr[i]);
        if (head == nullptr)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
}

int main()
{
    vector<int> arr = {3, 2, 0, 4, 6, 1};
    createList(arr);
    reverseLL();
    display();

    return 0;
}