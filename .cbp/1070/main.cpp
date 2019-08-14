#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cake{
    double storage;
    double price;
};

bool cmp(Cake &a, Cake &b){
    return (a.price / a.storage) > (b.price / b.storage);
}

vector<Cake> goods;
int main()
{
    int n;
    double total;
    scanf("%d %lf", &n, &total);
    goods.resize(n);
    for (int i = 0;i < n; i++)
        scanf("%lf", &goods[i].storage);
    for (int i = 0; i < n; i++)
        scanf("%lf", &goods[i].price);
    sort(goods.begin(), goods.end(), cmp);
    double maxp = 0.0;
    for (int i = 0; i < n; i++){
        double amo = min(goods[i].storage, total);
        maxp += (amo / goods[i].storage) * goods[i].price;
        total -= amo;
        if (total == 0)
            break;
    }
    printf("%.2f", maxp);
    return 0;
}
