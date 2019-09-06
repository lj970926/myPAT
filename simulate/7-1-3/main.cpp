#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int maxn = 10005;
vector<vector<int> > adj(maxn);
vector<int> color;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        unordered_set<int> h;
        int k = 0;
        color.clear();
        for (int j = 0; j < n; j++){
            int t;
            scanf("%d", &t);
            if (h.find(t) == h.end()){
                k++;
                h.insert(t);
            }
            color.push_back(t);
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
            printf("%d-coloring\n", k);
        else{
            printf("No\n");
        }
    }
    return 0;
}
