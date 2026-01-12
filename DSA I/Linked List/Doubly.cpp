#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    int value;
    struct Node *next = nullptr;
    struct Node *prev = nullptr;
};

void display(node *s)
{
    while (s != nullptr)
    {
        cout << s->value << "-->";
        s = s->next;
    }
    cout << "NULL";
}

int main()
{
    node *head = new node();
    node *n2 = new node();
    node *n3 = new node();
    node *n4 = new node();
    node *n5 = new node();

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    head->prev = nullptr;
    n2->prev = head;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;

    head->value = 7;
    n2->value = 12;
    n3->value = 8;
    n4->value = 65;
    n5->value = 10;

    node *cur = head;
    while (cur != nullptr)
    {
        if (cur->next == nullptr)
        {
            cur->next = cur->prev;
            cur->prev = nullptr;
            head = cur;
        }
        else
        {
            node *temp = new node();
            temp = cur;
            cur->prev = temp->next;
            cur->next = temp->prev;
            delete temp;
        }
        cur = cur->prev;
    }

    display(head);
    return 0;
}
