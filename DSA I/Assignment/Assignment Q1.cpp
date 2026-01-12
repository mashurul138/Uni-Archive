#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    string data;
    Node *next = nullptr;
};

node *head = nullptr;
node *tail = nullptr;

void add_Train(string s)
{
    node *temp = new node();
    temp->data = s;

    if (head == nullptr)
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void depart_Train(string s)
{
    if (head == nullptr)
    {
        cout << "There's no train to depart" << endl;
        return;
    }

    node *temp;
    if (head->data == s)
    {
        temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr; // List became empty
        delete temp;
        return;
    }

    node *cur = head;
    while (cur->next != nullptr && cur->next->data != s)
        cur = cur->next;

    if (cur->next == nullptr)
    {
        cout << "No Train found with id " << s << endl;
        return;
    }

    temp = cur->next;
    cur->next = temp->next;
    if (temp == tail)
        tail = cur;
    delete temp;
}

void emergency_Block(int i)
{
    if (head == nullptr)
    {
        cout << "There's no train on the track" << endl;
        return;
    }

    if (i == 0)
    {
        node *temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
        return;
    }

    node *cur = head;
    for (int index = 1; index < i && cur != nullptr; index++)
        cur = cur->next;
    if (cur == nullptr || cur->next == nullptr)
    {
        cout << "Invalid Index. Please enter valid index" << endl;
        return;
    }

    node *temp = cur->next;
    cur->next = temp->next;
    if (temp == tail)
        tail = cur;
    delete temp;
}

void display()
{
    if (head == nullptr)
    {
        cout << "There's no train on the track" << endl;
        return;
    }
    node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data;
        cur = cur->next;
        if (cur)
            cout << "--->";
    }
    cout << endl;
}

void menu()
{
    cout << "Operations: " << endl;
    cout << "1. Add a train" << endl;
    cout << "2. Depart a train" << endl;
    cout << "3. Emergency block a train" << endl;
    cout << "4. Display trains" << endl;
    cout << "Any other key to exit" << endl;
}

int main()
{
    int input;
    while (true)
    {
        menu();
        cin >> input;
        string s;
        int i;
        switch (input)
        {
        case 1:
            cout << "Enter Train ID: ";
            cin >> s;
            add_Train(s);
            break;
        case 2:
            cout << "Enter Train ID to depart: ";
            cin >> s;
            depart_Train(s);
            break;
        case 3:
            cout << "Enter Train index to block: ";
            cin >> i;
            emergency_Block(i);
            break;
        case 4:
            display();
            break;
        default:
            return 0;
        }
    }
}
