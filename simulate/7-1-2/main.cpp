#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node1{
    string id;
    int score;
    Node1(string i, int s): id(i), score(s){};
};
struct Node2{
    int cnt = 0, snum = 0;
};
struct Node3{
    string site;
    int num;
    Node3(string s, int n): site(s), num(n){};
};
map<char, vector<Node1> > lev;
map<string, Node2> site;
map<string, map<string, int> > date;

bool cmp1(Node1 a, Node1 b){
    return a.score == b.score ? a.id < b.id : a.score > b.score;
}

bool cmp2(Node3 a, Node3 b){
    return a.num == b.num ? a.site < b.site : a.num > b.num;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        string id;
        int score;
        cin >> id >> score;
        lev[id[0]].push_back(Node1(id, score));
        string st = id.substr(1, 3);
        site[st].cnt++;
        site[st].snum += score;
        string dt = id.substr(4, 6);
        date[dt][st]++;
    }
    for (int i = 0; i < m; i++){
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i + 1, type, term.c_str());
        if (type == 1){
            vector<Node1> &tmp = lev[term[0]];
            if (tmp.size() != 0){
                sort(tmp.begin(), tmp.end(), cmp1);
                for (int i = 0; i < tmp.size(); i++){
                    printf("%s %d\n", tmp[i].id.c_str(), tmp[i].score);
                }
            }
            else{
                printf("NA\n");
            }
        }
        else if (type == 2){
            if (site[term].cnt != 0){
                printf("%d %d\n", site[term].cnt, site[term].snum);
            }
            else
                printf("NA\n");
        }
        else if (type == 3){
            vector<Node3> tmp;
            for (auto it = date[term].begin(); it != date[term].end(); it++){
                tmp.push_back(Node3(it->first, it->second));
            }
            if (tmp.size() != 0){
                sort(tmp.begin(), tmp.end(), cmp2);
                for (int i = 0; i < tmp.size(); i++){
                    printf("%s %d\n", tmp[i].site.c_str(), tmp[i].num);
                }
            }
            else{
                printf("NA\n");
            }
        }
    }
    return 0;
}
