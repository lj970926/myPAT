#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1005;
int G[maxn][maxn];
vector<int> sus;
int father[maxn];
map<int, string > gang;
vector<string> res;
int findF(int x){
    if (father[x] == x)
        return x;
    return findF(father[x]);
}

void U(int x, int y){
    int fx= findF(x), fy = findF(y);
    if (fx != fy)
        father[fy] = fx;
}

int main()
{
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 0; i < m; i++){
        int a, b, du;
        scanf("%d %d %d", &a, &b, &du);
        G[a][b] += du;
    }
    for (int i = 1; i <= n; i++){
        int scall = 0, cback = 0;
        for (int j = 1; j <= n; j++){
            if (G[i][j] != 0 && G[i][j] <= 5){
                scall++;
                if (G[j][i] != 0)
                    cback++;
            }
        }
        if (scall > k && double(cback) / scall <= 0.2){
           sus.push_back(i);
        }
    }
    if (sus.size() == 0){
        printf("None\n");
        return 0;
    }
    sort(sus.begin(), sus.end());
    for (int i = 0; i < sus.size(); i++){
        for (int j = i + 1; j < sus.size(); j++){
            int a = sus[i], b = sus[j];
            if (G[a][b]!= 0 && G[b][a] != 0)
                U(a, b);
        }
    }
    for (int i = 0; i < sus.size(); i++){
        int fi = findF(sus[i]);
        if (gang.find(fi) != gang.end()){
            gang[fi] += " ";
        }
        gang[fi] += to_string(sus[i]);
    }
    for (auto it = gang.begin(); it != gang.end(); it++){
        string s = it->second;
        res.push_back(s);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++){
        printf("%s\n", res[i].c_str());
    }
    return 0;
}
