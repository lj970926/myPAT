#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
unordered_map<int, int> tree;
vector<int> in, pre;
int m, n;
unordered_map<string, int> ans;
void create(int i, int j, int p, int q){
    int mid;
    for (mid = i; in[mid] != pre[p]; mid++) ;
    if (mid != i){
        tree[pre[p + 1]]  = pre[p];
        create(i, mid - 1, p + 1, p + mid - i);
    }
    if (mid != j){
        tree[pre[p + mid - i + 1]] = pre[p];
        create(mid + 1, j, p + mid - i + 1, q);
    }
}

int findF(int u, int v){
    string s1 = to_string(u) +" " +  to_string(v);
    string s2 = to_string(v) + " " + to_string(u);
    if (ans.find(s1) != ans.end())
        return ans[s1];
    unordered_set<int> pu, pv;
    while (1){
        if (pv.find(u) != pv.end()){
            ans[s1] = ans[s2] = u;
            return u;
        }
        pu.insert(u);
        u = tree[u];
        if (pu.find(v) != pu.end()){
            ans[s1] = ans[s2] = v;
            return v;
        }
        pv.insert(v);
        v = tree[v];
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    in.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    create(0, n - 1, 0, n - 1);
    tree[pre[0]] = pre[0];
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        if (tree.find(u) == tree.end() && tree.find(v) == tree.end()){
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if (tree.find(u) == tree.end()){
            printf("ERROR: %d is not found.\n", u);
        }
        else if (tree.find(v) == tree.end()){
            printf("ERROR: %d is not found.\n", v);
        }
        else{
            int a = findF(u, v);
            if (a == u || a == v)
                printf("%d is an ancestor of %d.\n", a, u == a ? v : u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
}
