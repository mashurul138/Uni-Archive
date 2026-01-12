#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Items
{
    int no;
    double weight, value, valPWei;
    string name;
};

struct thieves
{
    int nu;
    double th_cap, profit;
};

bool compare(Items a, Items b)
{

    return a.valPWei > b.valPWei;
}

int main()
{
    int n;
    cin >> n;
    vector<Items> item(n);

    for (int i = 0; i < n; i++)
    {
        string name;
        double weight, value;
        cin >> name >> value >> weight;
        item[i].name = name;
        item[i].value = value;
        item[i].weight = weight;
        item[i].valPWei = value / weight;
        item[i].no = i + 1;
    }

    sort(item.begin(), item.end(), compare);

    int m;
    cin >> m;
    vector<thieves> thieve(m);

    for (int i = 0; i < m; i++)
    {
        double p;
        cin >> p;
        thieve[i].th_cap = p;
        thieve[i].nu = i + 1;
    }

    // for (int i = 0; i < n; i++)
    // {

    //     cout << item[i].weight << " " << item[i].value << " " << item[i].valPWei << endl;
    // }

    int itemIndex = 0;

    // Outer loop for thieves
    for (int i = 0; i < m; i++)
    {
        while (thieve[i].th_cap > 0 && itemIndex < n)
        {
            double currentItemWeight = item[itemIndex].weight;
            double currentItemValue = item[itemIndex].value;

            if (currentItemWeight <= thieve[i].th_cap)
            {
                thieve[i].th_cap -= currentItemWeight;
                thieve[i].profit += currentItemWeight * item[itemIndex].valPWei;
                item[itemIndex].weight = 0;
                cout << "Taking " << item[itemIndex].name << " : " << currentItemWeight << " kg " << currentItemWeight * item[itemIndex].valPWei << " tk" << endl;
                itemIndex++;
            }
            else
            {
                double fraction = thieve[i].th_cap / currentItemWeight;
                thieve[i].profit += thieve[i].th_cap * (currentItemValue / currentItemWeight);
                item[itemIndex].weight -= thieve[i].th_cap;
                cout << "Taking " << item[itemIndex].name << " : " << thieve[i].th_cap << " kg " << fraction * currentItemValue << " tk" << endl;
                thieve[i].th_cap = 0;
                break;
            }
        }
        cout << "Thief " << thieve[i].nu << " profit: " << thieve[i].profit << " tk" << endl;
    }
}