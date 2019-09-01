#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Node1{
    string id;
    int sco;
    Node1(string i, int s):id(i), sco(s){};
};
struct Node2{
    int num = 0, sco = 0;
};
struct Node3{
    int sid, num;
};
map<char, vector<Node1> > score;
Node2 site[1005];
map<int, map<int, int> > date;

bool cmp1(Node1 a, Node1 b){
    return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp3(Node3 a, Node3 b){
    return a.num == b.num ? a.sid < b.sid : a.num > b.num;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        string id;
        int sco;
        cin >> id >> sco;
        score[id[0]].push_back(Node1(id, sco));
        int st = stoi(id.substr(1, 3));
        site[st].num++;
        site[st].sco += sco;
        int dt = stoi(id.substr(4, 6));
        date[dt][st]++;
    }
    for (auto it = score.begin(); it != score.end(); it++){
        vector<Node1>& tmp = it->second;
        sort(tmp.begin(), tmp.end(), cmp1);
    }
    for (int i = 0; i < m; i++){
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i + 1, type, term.c_str());
        if (type == 1){
            vector<Node1>& tmp = score[term[0]];
            if (tmp.size() == 0)
                printf("NA\n");
            else
            for (int j = 0; j < tmp.size(); j++){
                printf("%s %d\n", tmp[j].id.c_str(), tmp[j].sco);
            }
        }
        else if (type == 2){
            int st = stoi(term);
            if (site[st].num == 0)
                printf("NA\n");
            else
                printf("%d %d\n", site[st].num, site[st].sco);
        }
        else if (type == 3){
            int dt = stoi(term);
            vector<Node3> tmp;
            for (auto it = date[dt].begin(); it != date[dt].end(); it++){
                Node3 t;
                t.sid = it->first;
                t.num = it->second;
                tmp.push_back(t);
            }
            if (tmp.size() == 0)
                printf("NA\n");
            else{
                sort(tmp.begin(), tmp.end(), cmp3);
                for (int j = 0; j < tmp.size(); j++){
                    printf("%03d %d\n", tmp[j].sid, tmp[j].num);
                }
            }
        }
    }
    return 0;

}
