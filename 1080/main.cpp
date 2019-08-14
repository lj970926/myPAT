#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct Stu{
    int id, Ga, Ge;
    vector<int> cho;
    Stu(int i, int a, int e, vector<int> c):id(i), Ga(a), Ge(e), cho(c){};
};
struct Sch{
    int la = -1, le = -1;
    set<int> app;
};
vector<int> quota;
vector<Stu> stu;
vector<Sch> sch;

bool cmp(Stu &a, Stu &b){
    return (a.Ga > b.Ga || (a.Ga == b.Ga && a.Ge > b.Ge));
}

void enroll(Stu &a){
    for (int i = 0; i < a.cho.size(); i++){
        int ch = a.cho[i];
        if (sch[ch].app.size() < quota[ch] || (sch[ch].la == a.Ga && sch[ch].le == a.Ge)){
            sch[ch].app.insert(a.id);
            sch[ch].la = a.Ga;
            sch[ch].le = a.Ge;
            break;
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    quota.resize(m);
    sch.resize(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &quota[i]);
    for (int i = 0; i < n; i++){
        int ti, te;
        vector<int> tc(k);
        scanf("%d %d", &te, &ti);
        for (int j = 0; j < k; j++){
            scanf("%d", &tc[j]);
        }
        stu.push_back(Stu(i, ti + te, te, tc));
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++){
        enroll(stu[i]);
    }
    for (int i = 0; i < m; i++){
        for (auto itr = sch[i].app.begin(); itr != sch[i].app.end(); itr++){
            if (itr != sch[i].app.begin())
                printf(" ");
            printf("%d", *itr);
        }
        printf("\n");
    }
    return 0;
}
