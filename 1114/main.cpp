#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int sid, mem;
    double area, sets;
    node(int s, int m, double a, double se):sid(s), mem(m), area(a), sets(se){};
};
int f[10005], sid[10005], mem[10005];
double sets[10005], area[10005];
vector<node> res;

bool cmp(node a, node b){
    return a.area == b.area ? a.sid < b.sid : a.area > b.area;
}

int findF(int x){
    if (f[x] == x)
        return x;
    return findF(f[x]);
}
void U(int x, int y){
    int fx = findF(x);
    int fy = findF(y);
    if (fx != fy)
        f[fy] = fx;
}

int main()
{
    fill(sid, sid + 10005, 0x3fffffff);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10000; i++)
        f[i] = i;
    for (int i = 0; i < n; i++){
        int id, fa, mo, k;
        scanf("%d %d %d %d", &id, &fa, &mo, &k);
        if (fa != -1)
            U(id, fa);
        if (mo != -1)
            U(id, mo);
        for (int j = 0; j < k; j++){
            int t;
            scanf("%d", &t);
            U(id, t);
        }
        scanf("%lf %lf", &sets[id], &area[id]);
    }
    for (int i = 0; i < 10000; i++){
        int fi = findF(i);
        if (fi != i){
            sets[fi] += sets[i];
            area[fi] += area[i];
        }
        mem[fi]++;
        if (i < sid[fi])
            sid[fi] = i;
    }
    for (int i = 0; i < 10000; i++){
        if (f[i] == i && area[i] != 0)
            res.push_back(node(sid[i], mem[i], area[i] / mem[i], sets[i] / mem[i]));
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++){
        printf("%04d %d %.3f %.3f\n", res[i].sid, res[i].mem, res[i].sets, res[i].area);
    }
    return 0;
}
