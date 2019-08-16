#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<set<int> > sets;
void calc(int a1, int b1){
    set<int> a = sets[a1];
    set<int> b = sets[b1];
    int n = a.size() + b.size();
    a.insert(b.begin(), b.end());
    int nt = a.size(), nc = n - nt;
    double res = (double)nc / nt * 100;
    printf("%.1f%%\n", res);
}

int main()
{
    int n;
    scanf("%d", &n);
    sets.resize(n + 1);
    for (int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            int t;
            scanf("%d", &t);
            sets[i].insert(t);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        int m, j;
        scanf("%d %d", &m, &j);
        calc(m, j);
    }
    return 0;
}
