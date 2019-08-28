#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> pre;
map<int, bool> has;
int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    pre.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
        has[pre[i]] = true;
    }

    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        if (!has[u] && !has[v]){
            printf("ERROR: %d and %d are not found.\n", u, v);
            continue;
        }
        if (!has[u]){
            printf("ERROR: %d is not found.\n", u);
            continue;
        }
        if (!has[v]){
            printf("ERROR: %d is not found.\n", v);
            continue;
        }
        int lo = min(u, v), hi = max(u, v);
        int a;
        for (int j = 0; j < n; j++){
            if (pre[j] >= lo && pre[j] <= hi){
                a = pre[j];
                break;
            }
        }
        if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
