#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
const int maxn = 100000;
unordered_set<int> G[maxn];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].insert(b);
        G[b].insert(a);
    }
    for (int i = 0; i < m; i++){
        vector<int> tmp;
        int k;
        scanf("%d", &k);
        tmp.resize(k);
        for (int j = 0; j < k; j++){
            scanf("%d", &tmp[j]);
        }
        vector<bool> h(maxn, false);
        int j;
        for (j = 0; j < k; j++){
            if (h[tmp[j]]){
                printf("No\n");
                break;
            }
            for (auto it = G[tmp[j]].begin(); it != G[tmp[j]].end(); it++)
                h[*it] = true;
        }
        if (j == k)
            printf("Yes\n");
    }
    return 0;
}
