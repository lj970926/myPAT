#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int lev,v;
    Node(int l_, int v_):lev(l_),v(v_){};
};
const int maxn = 1005;
int n,l,m,k;
vector<int> adj[maxn];

void bfs(int u){
    int total = 0;
    queue<Node> q;
    q.push(Node(0,u));
    bool inq[maxn] = {false};
    inq[u] = true;
    while (!q.empty()){
        Node t = q.front();
        q.pop();
        int v = t.v;
        if (t.lev > l){
            break;
        }
        if (t.lev > 0)
            total += 1;
        for (int i = 0; i < adj[v].size(); i++){
            int w = adj[v][i];
            if (!inq[w]){
                q.push(Node(t.lev + 1,w));
                inq[w] = true;
            }
        }
    }
    printf("%d\n",total);

}

int main()
{
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++){
        scanf("%d", &m);
        for (int j = 0; j < m; j++){
            int t;
            scanf("%d", &t);
            adj[t].push_back(i);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int q;
        scanf("%d", &q);
        bfs(q);
    }
    return 0;
}
