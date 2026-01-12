#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    char pixel;
    int cnt;
    struct Node *next;

    Node(char c, int i)
    {
        pixel = c;
        cnt = i;
    }
};

void insert(node *&head, int count, char ch)
{
    node *newNode = new node(ch, count);
    if (!head)
    {
        head = newNode;
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void createNode(string s, node *&head)
{
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            insert(head, cnt, s[i - 1]);
            cnt = 1;
        }
    }
    insert(head, cnt, s[s.size() - 1]);
}

void mirror_Display(node *head)
{
    string res = "";
    node *temp = head;
    while (temp)
    {
        string str(temp->cnt, temp->pixel);
        res = str + res;
        temp = temp->next;
    }
    cout << res << endl;
}

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    cin.ignore();
    string row[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter row " << i + 1 << " : ";
        cin >> row[i];
        node *head = nullptr;
        createNode(row[i], head);
        cout << "After mirror : ";
        mirror_Display(head);
    }
    return 0;
}