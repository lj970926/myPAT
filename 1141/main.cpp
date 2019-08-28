#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct Node1{
    int ta = 0, tt = 0, tb = 0, num = 0;
};
struct Node2{
    string name;
    int tws, ns;
    Node2(string nm, int t, int n):name(nm), tws(t), ns(n){};
};

map<string, Node1> school;
vector<Node2> r;

void lower(string& s){
    for (int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
}

bool cmp(Node2 a, Node2 b){
    if (a.tws != b.tws)
        return a.tws > b.tws;
    if (a.ns != b.ns)
        return a.ns < b.ns;
    return a.name < b.name;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string id,sch;
        int sco;
        cin >> id >> sco >> sch;
        lower(sch);
        school[sch].num++;
        if (id[0] == 'A')
            school[sch].ta += sco;
        else if (id[0] == 'T')
            school[sch].tt += sco;
        else
            school[sch].tb += sco;
    }
    for (auto it = school.begin(); it != school.end(); it++){
        string name = it->first;
        Node1 &tmp = it->second;
        int tws = (tmp.tt * 1.5 + tmp.ta + tmp.tb / 1.5);
        int num = tmp.num;
        r.push_back(Node2(name, tws, num));
    }
    sort(r.begin(), r.end(), cmp);
    printf("%d\n", int(r.size()));
    int tr = 1;
    for (int i = 0; i < r.size(); i++){
        if (i != 0 && r[i].tws != r[i - 1].tws)
            tr = i + 1;
        printf("%d %s %d %d\n", tr, r[i].name.c_str(), r[i].tws, r[i].ns);
    }
    return 0;
}
