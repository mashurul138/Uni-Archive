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

bool hasCycle()
{
    node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

void createCircularList(vector<int> arr, int circlePos)
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
        if (i == circlePos)
            circleNode = temp;
    }
    if (circlePos >= 0 && circlePos < arr.size())
        temp->next = circleNode;
}

int main()
{
    vector<int> arr = {3, 2, 0, 4, 6, 1};
    createCircularList(arr, 7);

    if (hasCycle())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}