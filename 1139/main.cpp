#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 305;
map<string, int> sti;
string its[maxn];
int G[maxn][maxn];
bool vis[maxn];
int n, m, index = 1;
set<string> ans;
vector<int> tmp;
int sym[2][2] = {{1, -1}, {1, 1}};

int gend(int x){
    string s= its[x];
    if (s[0] == '-')
        return -1;
    else
        return 1;
}

void dfs(int s, int d, int i, int j){
    tmp.push_back(s);
    vis[s] = true;
    if (j == 2){
        if (G[s][d] != 0){
            string left = its[tmp[1]], right = its[tmp[2]];
            left = left[0] == '-' ? left.substr(1) : left;
            right = right[0] == '-' ? right.substr(1) : right;
            ans.insert(left + " " + right);
        }
        tmp.pop_back();
        vis[s] = false;
        return;
    }
    for (int k = 1; k <= n; k++){
        if (!vis[k] && G[s][k] != 0 && gend(s) * gend(k) == sym[i][j] && k != d){
            dfs(k, d, i, j + 1);
        }
    }
    tmp.pop_back();
    vis[s] = false;
}

void solve(string a, string b){
    ans.clear();
    int s = sti[a], d = sti[b];
    if (gend(s) != gend(d))
        dfs(s, d, 0, 0);
    else
        dfs(s, d, 1, 0);
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        if (sti.find(a) == sti.end()){
            sti[a] = index;
            its[index++] = a;
        }
        if (sti.find(b) == sti.end()){
            sti[b] = index;
            its[index++] = b;
        }
        int ia = sti[a], ib = sti[b];
        G[ia][ib] = G[ib][ia] = 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        string a, b;
        cin >> a >> b;
        solve(a, b);
        printf("%d\n", ans.size());
        for (auto it = ans.begin(); it != ans.end(); it++){
            cout << *it << endl;
        }
    }
    return 0;
}
