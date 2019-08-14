#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv = 2005;
int G[maxv][maxv] = {0};
map<string, int> num;
string name[maxv];
bool vis[maxv] = {false};
int n,k,anum = 0;
int len[maxv] = {0};
int thr[maxv] = {0};
vector<int> temp;
vector <string> ans;
void dfs(int u){
    vis[u] = true;
    temp.push_back(u);
    for (int v = 0; v < num.size(); v++){
        thr[u] += G[u][v];
        if (G[u][v] != 0 && !vis[v]){
            len[u]++;
            dfs(v);

        }
    }
}

void DFS(){
    for (int i = 0; i < num.size();i++){
        temp.clear();
        if (!vis[i]){
            dfs(i);
            int totalk = 0,maxnum = temp[0];
            for (int j = 0; j < temp.size(); j++){
                totalk += thr[temp[j]];
                if (thr[temp[j]] > thr[maxnum])
                    maxnum = temp[j];
            }
            totalk /= 2;
            if (temp.size() > 2 && totalk > k){
                anum++;
                ans.push_back(name[maxnum] + " " + to_string(temp.size()));
            }
        }


    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        string a, b;
        int time;
        cin >> a >> b >> time;
        if (num.find(a) == num.end()){
            int no = num.size();
            num[a] = no;
            name[no] = a;
        }

        if (num.find(b) ==  num.end()){
            int no = num.size();
            num[b] = no;
            name[no] = b;
        }
        int u = num[a], v = num[b];
        G[u][v] += time;
        G[v][u] += time;
    }
    DFS();
    printf("%d", anum);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++){
        printf("\n");
        printf(ans[i].c_str());
    }
    return 0;
}
