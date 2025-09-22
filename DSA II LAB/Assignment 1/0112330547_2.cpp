#include <bits/stdc++.h>

using namespace std;

struct Drink
{
    string name;
    double size;
    double glucose;
    double gpl = glucose / size;
};

int compare(Drink a, Drink b)
{
    return a.gpl < b.gpl;
}

int main()
{
    int maxi = 6;
    vector<Drink> drinks = {
        {"Galxose-D", 3, 75},
        {"GlucoMax", 4, 80},
        {"Sting", 5, 150}};
    sort(drinks.begin(), drinks.end(), compare);
    double total = 0, rem = maxi;
    cout << "Drinks taken: " << endl;
    for (Drink &d : drinks)
    {
        if (rem == 0)
            break;
        double take = min(d.size, rem);
        total += take * d.gpl;
        rem -= take;
        cout << d.name << ": " << take << "L" << endl;
    }
    cout << "Glucose consumed: " << total << "gm" << endl;
    return 0;
}