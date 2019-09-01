#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int maxn = 10005;
vector<vector<int> > adj;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    adj.resize(n);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        vector<int> color(n);
        unordered_set<int> h;
        int num = 0;
        for (int j = 0; j < n; j++){
            int t;
            scanf("%d", &t);
            if (h.find(t) == h.end()){
                num++;
                h.insert(t);
            }
            color[j] = t;
        }
        bool flag = true;
        for (int j = 0; j < n && flag; j++){
            for (int p = 0; p < adj[j].size(); p++){
                if (color[j] == color[adj[j][p]]){
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            printf("%d-coloring\n", num);
        else
            printf("No\n");
    }
    return 0;
}
