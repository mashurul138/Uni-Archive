#include <bits/stdc++.h>

using namespace std;

struct Product
{
    string name;
    double weight, wSale, rpk, ppk;
};

int compare(Product a, Product b)
{
    return a.ppk > b.ppk;
}

int main()
{
    double capacity;
    cin >> capacity;
    vector<Product> products = {
        {"Rice", 100, 4000, 55},
        {"Sugar", 200, 9000, 62},
        {"Wheat", 350, 7000, 30},
        {"Onion", 250, 12000, 80}};
    for (Product &p : products)
    {
        double wpk = p.wSale / p.weight;
        p.ppk = p.rpk - wpk;
    }
    sort(products.begin(), products.end(), compare);
    double maxi = 0, rem = capacity;
    cout << "Products to purchase: " << endl;
    for (Product &p : products)
    {
        if (rem == 0)
            break;
        double take = min(p.weight, rem);
        maxi += take * p.ppk;
        rem -= take;
        cout << p.name << ": " << take << " kg" << endl;
    }
    cout << "Maximum profit: " << maxi << endl;
    return 0;
}
