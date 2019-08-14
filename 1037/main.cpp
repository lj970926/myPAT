#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> coupons,products;
    int nc,np;
    cin >> nc;
    for (int i = 0; i< nc;i++){
        int temp;
        cin >> temp;
        coupons.push_back(temp);
    }
    cin >> np;
    for (int i = 0;i < np;i++){
        int temp;
        cin >> temp;
        products.push_back(temp);
    }
    sort(coupons.begin(),coupons.end());
    sort(products.begin(),products.end());
    long long sum = 0;
    int pos = 0;
    while(pos < coupons.size() && pos < products.size()&&coupons[pos] < 0 && products[pos] < 0){
        sum += (coupons[pos]*products[pos]);
        pos++;
    }
    pos = coupons.size() - 1;
    int posp = products.size() - 1;
    while (pos >= 0&& posp >= 0&&coupons[pos] > 0 && products[posp] > 0){
        sum += (coupons[pos]*products[posp]);
        pos--;
        posp--;
    }
    cout << sum;
    return 0;
}
