#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node{
    string name;
    int ga = -1, gm = -1, gf = -1, g = -1;
};
map<string, int> ass;
map<string, int> mid;
vector<Node> qua;

bool cmp(Node a, Node b){
    return a.g == b.g ? a.name < b.name : a.g > b.g;
}

int main()
{
    int p, m, n;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++){
        string name;
        int g;
        cin >> name >> g;
        if (g >= 200)
            ass[name] = g;
    }
    for (int i = 0; i < m; i++){
        string name;
        int g;
        cin >> name >> g;
        mid[name] = g;
    }
    for (int i = 0; i < n; i++){
        string name;
        int g;
        cin >> name >> g;
        if (ass.find(name) != ass.end()){
            Node tmp;
            tmp.gf = g;
            tmp.ga = ass[name];
            tmp.name = name;
            int fg;
            if (mid.find(name) != mid.end()){
                fg = round(mid[name] > g ? mid[name] * 0.4 + 0.6 * g : g);
                tmp.gm = mid[name];
            }
            else
                fg = g;
            tmp.g = fg;
            if (tmp.g >= 60.0){
                qua.push_back(tmp);
            }
        }
    }
    sort(qua.begin(), qua.end(), cmp);
    for (int i = 0; i < qua.size(); i++){
        printf("%s %d %d %d %d\n", qua[i].name.c_str(), qua[i].ga, qua[i].gm, qua[i].gf, qua[i].g);
    }
    return 0;
}
