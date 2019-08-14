#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Peo{
    int id, vgrad, tgrad, r;
    Peo(int i, int v, int t, int r_):id(i), vgrad(v), tgrad(t),r(r_){};
};
vector<Peo> peo;

bool cmp(Peo &a, Peo &b){
    if (a.r != b.r)
        return a.r < b.r;
    if (a.tgrad + a.vgrad != b.tgrad + b.vgrad)
        return a.tgrad + a.vgrad > b.tgrad + b.vgrad;
    if (a.vgrad != b.vgrad)
        return a.vgrad > b.vgrad;
    return a.id < b.id;
}

int main()
{
    int n,l,h;
    scanf("%d %d %d", &n, &l, &h);
    int m = 0;
    for (int i = 0; i < n; i++){
        int ti, tv, tt, r;
        scanf("%d %d %d", &ti, &tv, &tt);
        if (tv >= l && tt >= l){
            m++;
            if (tv >= h && tt >= h)
                r = 1;
            else if (tv >= h && tt < h)
                r = 2;
            else if (tv < h && tt < h && tv >= tt)
                r = 3;
            else
                r = 4;
            peo.push_back(Peo(ti, tv, tt, r));
        }
    }
    sort(peo.begin(), peo.end(), cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%08d %d %d\n", peo[i].id, peo[i].vgrad, peo[i].tgrad);
    return 0;
}
