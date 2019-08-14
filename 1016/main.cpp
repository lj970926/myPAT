#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec{
    int mo, dd, hh, mm, tp;
    Rec(int mo_, int dd_, int hh_, int mm_, int tp_):mo(mo_), dd(dd_), hh(hh_), mm(mm_), tp(tp_){};
};

double toll[25];
map<string, vector<Rec> > rec;

int tti(Rec a){
    return a.dd * 24 * 60 + a.hh * 60 + a.mm;
}

double ttd(Rec a){
    double ans = a.dd * toll[24]  + toll[a.hh];
    ans *= 60;
    ans += a.mm * (toll[a.hh + 1] - toll[a.hh]);
    return ans / 100;
}

bool cmp(Rec a, Rec b){
    return tti(a) < tti(b);
}

int main()
{
    toll[0] = 0;
    for (int i = 1;i < 25; i++){
        scanf("%lf", &toll[i]);
        toll[i] += toll[i - 1];
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string n1, ty;
        int mo, hh, dd, mm;
        cin >> n1;
        scanf("%d:%d:%d:%d", &mo, &dd, &hh, &mm);
        cin >> ty;
        int tp = ty[1] == 'n' ? 1 : 2;
        rec[n1].push_back(Rec(mo, dd, hh, mm, tp));
    }
    for (auto it = rec.begin(); it != rec.end(); it++){
        vector<Rec> tmp;
        vector<Rec> &r = it->second;
        sort(r.begin(), r.end(), cmp);
        for (int i = 0; i < r.size() - 1; i++){
            if (r[i].tp == 1 && r[i + 1].tp == 2){
                tmp.push_back(r[i]);
                tmp.push_back(r[i + 1]);
            }
        }
        if (tmp.size() != 0){
            double sum = 0.0;
            printf(it->first.c_str());
            printf(" %02d\n", r.begin()->mo);
            for (int i = 0; i < tmp.size(); i += 2){
                Rec a = tmp[i], b = tmp[i + 1];
                double co = ttd(b) - ttd(a);
                sum += co;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", a.dd, a.hh, a.mm, b.dd, b.hh, b.mm, tti(b) - tti(a), co);
            }
            printf("Total amount: $%.2f\n", sum);
        }

    }
    return 0;
}
