#include <bits/stdc++.h>

using namespace std;

struct student
{
    string name, id;
    double cgpa;
};

student highestCGPA(vector<student> st, int l, int h)
{
    if (l == h)
        return st[l];
    int m = (l + h) / 2;
    student left = highestCGPA(st, l, m);
    student right = highestCGPA(st, m + 1, h);
    if (left.cgpa > right.cgpa)
        return left;
    return right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<student> students = {
        {"mashurul", "1", 3.33},
        {"haque", "2", 3.67},
        {"mhi", "4", 4},
        {"ibtid", "3", 3.89}};

    student highest = highestCGPA(students, 0, students.size() - 1);
    cout << highest.name << " " << highest.id << " " << highest.cgpa << endl;
    return 0;
}