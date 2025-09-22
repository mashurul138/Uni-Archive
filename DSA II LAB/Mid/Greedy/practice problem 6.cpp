#include <bits/stdc++.h>

using namespace std;

struct train
{
    int arrival, departure;
};

bool compare(train a, train b)
{
    return a.departure < b.departure;
}

vector<int> maxUse(vector<train> trains)
{
    vector<int> res;
    res.push_back(0);
    int lastDeparture = trains[0].departure;
    for (int i = 1; i < trains.size(); i++)
    {
        if (trains[i].arrival >= lastDeparture + 10)
        {
            lastDeparture = trains[i].departure;
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<train> trains = {{1000, 1030},
                            {840, 1030},
                            {850, 1040},
                            {1700, 2000},
                            {800, 835},
                            {1300, 1800},
                            {1500, 1650},
                            {1200, 1380}};
    sort(trains.begin(), trains.end(), compare);

    for (auto i : trains)
        cout << i.arrival << " " << i.departure << endl;
    vector<int> ans = maxUse(trains);
    cout << ans.size() << endl;
    if (!ans.empty())
    {
        cout << "selected Trains: ";
        for (int i : ans)
            cout << (i + 1) << " ";
    }
    return 0;
}