#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Car{
    int time;
    string type;
};
int ttos(int hh, int mm, int ss){
    return hh * 60 * 60 + mm * 60 + ss;
}

map<string, vector<Car> > mes;
map<string, int> wtime;
int num[24* 60 *60 + 10] = {0}, maxw = 0;
set<string> ans;

bool cmp(Car a, Car b){
    return a.time < b.time;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        char ii[8], tt[4];
        int hh,mm,ss;
        scanf("%s %d:%d:%d %s", ii, &hh, &mm, &ss, tt);
        string id = ii, type = tt;
        Car c;
        c.time = ttos(hh,mm,ss);
        c.type = type;
        mes[id].push_back(c);
    }
    for (auto itr = mes.begin(); itr != mes.end(); itr++){
        string id = itr->first;
        vector<Car> &a = itr->second;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0 ; i < a.size() - 1; i++){
            if (a[i].type == "in" && a[i + 1].type =="out"){
                int wait = a[i + 1].time - a[i].time;
                wtime[id] += wait;
                if (wtime[id] > maxw){
                    maxw = wtime[id];
                    ans.clear();
                    ans.insert(id);
                } else if (wtime[id] == maxw)
                    ans.insert(id);
                for (int m = a[i].time; m < a[i + 1].time; m++)
                    num[m]++;
            }

        }
    }
    for (int i = 0; i < k; i++){
        int hh, mm ,ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = ttos(hh,mm,ss);
        printf("%d\n", num[t]);
    }
    for (auto itr = ans.begin();itr != ans.end();itr++){
        printf("%s ", (*itr).c_str());
    }
    int wh, wm ,ws;
    wh = maxw / 3600;
    wm = maxw % 3600 /60;
    ws = maxw % 3600 % 60;
    printf("%02d:%02d:%02d", wh, wm, ws);
    return 0;
}
