#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string name;
    double weight, value, ratio;
};

int main()
{
    // Items: name, weight, value
    vector<Item> items = {
        {"Rice", 12, 840, 0},
        {"Salt", 10, 870, 0},
        {"Saffron", 8, 2000, 0},
        {"Sugar", 5, 500, 0}};

    // Calculate value/weight ratio
    for (auto &it : items)
        it.ratio = it.value / it.weight;

    // Sort by ratio descending
    sort(items.begin(), items.end(), [](Item &a, Item &b)
         { return a.ratio > b.ratio; });

    int thiefCount = 0;
    vector<vector<pair<string, double>>> thieves; // thief -> items stolen
    vector<double> profits;

    double capacity = 9;

    while (true)
    {
        double remain = capacity, profit = 0;
        vector<pair<string, double>> stolen;
        bool tookSomething = false;

        for (auto &it : items)
        {
            if (it.weight > 0 && remain > 0)
            {
                double take = min(it.weight, remain);
                it.weight -= take;
                remain -= take;
                profit += take * it.ratio;
                stolen.push_back({it.name, take});
                tookSomething = true;
            }
        }

        if (!tookSomething)
            break; // no more items

        thieves.push_back(stolen);
        profits.push_back(profit);
        thiefCount++;
    }

    cout << "Total thieves needed: " << thiefCount << "\n\n";
    for (int i = 0; i < thiefCount; i++)
    {
        cout << "Thief " << i + 1 << " steals:\n";
        for (auto &p : thieves[i])
        {
            cout << "  " << p.second << " kg of " << p.first << "\n";
        }
        cout << "Profit: " << profits[i] << " taka\n\n";
    }

    return 0;
}
