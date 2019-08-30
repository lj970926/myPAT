#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > adj;
vector<int> ans;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        vector<bool> h(n + 1, false);
        vector<int> tmp(n);
        bool res = true;
        for (int j = 0; j < n; j++){
            scanf("%d", &tmp[j]);
        }
        for (int j = 0; j < n && res; j++){
            int t = tmp[j];
            for (int p = 0; p < adj[t].size(); p++){
                if (h[adj[t][p]]){
                    res = false;
                    break;
                }
            }
            h[t] = true;
        }
        if (!res)
            ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++){
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
