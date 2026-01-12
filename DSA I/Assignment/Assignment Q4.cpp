#include <bits/stdc++.h>

using namespace std;
typedef struct Node node;

struct Node
{
    int coef;
    int expo;
    struct Node *next;

    Node(int c, int e)
    {
        coef = c;
        expo = e;
    }
};

void insert(Node *&head, int coef, int expo)
{
    node *newNode = new Node(coef, expo);

    if (!head || expo > head->expo)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    node *prev = nullptr;

    while (temp && temp->expo > expo)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp && temp->expo == expo)
        temp->coef += coef;
    else
    {
        newNode->next = temp;
        if (prev)
            prev->next = newNode;
        else
            head = newNode;
    }
}

void createNode(string s, node *&head)
{
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
            i++;
        int c = 0, e = 0;
        bool neg = false;
        if (s[i] == '+')
            i++;
        if (s[i] == '-')
        {
            neg = true;
            i++;
        }
        if (s[i] == ' ')
            i++;
        while (isdigit(s[i]))
        {
            c = c * 10 + (s[i] - '0');
            i++;
        }
        if (neg)
            c *= -1;
        if (s[i] == 'x')
        {
            i++;
            if (s[i] == '^')
            {
                i++;
                while (isdigit(s[i]))
                {
                    e = e * 10 + (s[i] - '0');
                    i++;
                }
            }
            else
                e = 1;
        }
        else
            e = 0;
        insert(head, c, e);
    }
}

Node *add(Node *poly1, Node *poly2)
{
    Node *res = nullptr;
    while (poly1 && poly2)
    {
        if (poly1->expo == poly2->expo)
        {
            insert(res, poly1->coef + poly2->coef, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->expo > poly2->expo)
        {
            insert(res, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        }
        else
        {
            insert(res, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        }
    }

    while (poly1)
    {
        insert(res, poly1->coef, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2)
    {
        insert(res, poly2->coef, poly2->expo);
        poly2 = poly2->next;
    }
    return res;
}

void display(Node *cur)
{
    while (cur)
    {
        cur->coef >= 0 ? cout << cur->coef : cout << "- " << abs(cur->coef);
        if (cur->expo != 0)
            cur->expo != 1 ? cout << "x^" << cur->expo : cout << "x";
        if (cur->next && cur->next->coef >= 0)
            cout << " + ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    node *poly1 = nullptr;
    node *poly2 = nullptr;

    string pol1, pol2;

    cout << "Enter 1st polynomial: ";
    getline(cin, pol1);
    cout << "Enter 2nd polynomial: ";
    getline(cin, pol2);

    createNode(pol1, poly1);
    createNode(pol2, poly2);

    node *result = add(poly1, poly2);

    cout << "After Addition: ";
    display(result);

    return 0;
}
