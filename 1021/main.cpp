#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    int v,lev;
    Node(int v_, int l_):v(v_),lev{l_}{};
};

const int maxn = 100005;
vector<int> adj[maxn];
int father[maxn];
bool inq[maxn] = {false};
int n;

int findF(int x){
    if (father[x] == x)
        return x;
    int f = findF(father[x]);
    father[x] = f;
    return f;
}

void U(int x, int y){
    int fx = findF(x);
    int fy = findF(y);
    if (fx != fy){
        father[fy] = fx;
    }
}

int calB(){
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (father[i] == i)
            res++;
    }
    return res;
}

void BFS(int u,set<int> &ans){
    queue<Node> q;
    q.push(Node(u,1));
    inq[u] = true;
    int maxl = 0;
    while (!q.empty()){
        int v  = q.front().v;
        int l = q.front().lev;
        q.pop();
        if (l > maxl){
            ans.clear();
            ans.insert(v);
            maxl = l;
        } else if (l == maxl){
            ans.insert(v);
        }
        for (int i = 0; i < adj[v].size(); i++){
            int w = adj[v][i];
            if (!inq[w]){
                q.push(Node(w, l + 1));
                inq[w] = true;
            }
        }
    }
    fill(inq, inq + n + 1, false);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        U(u,v);
    }
    if (calB() > 1)
        printf("Error: %d components", calB());
    else{
        set<int> a,b;
        BFS(1,a);
        auto itr = a.begin();
        BFS(*itr,b);
        a.insert(b.begin(), b.end());
        for (itr = a.begin(); itr != a.end(); itr++){
            printf("%d\n", *itr);
        }
    }
    return 0;
}
