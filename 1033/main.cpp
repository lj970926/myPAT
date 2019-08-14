#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Sta{
    int dis;
    double pri;
};
vector<Sta> sta;

bool cmp(Sta &a, Sta &b){
    return a.dis < b.dis;
}

int main()
{
    int cmax, d, davg, n;
    scanf("%d %d %d %d", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; i++){
        Sta t;
        scanf("%lf, %d", &t.pri, &t.dis);
        sta.push_back(t);
    }
    sort(sta.begin(), sta.end(), cmp);
    if (sta[0].dis != 0)
        printf("The maximum travel distance = 0.00");
    else{
        int i = 0;
        while (i < n){
            if (sta[i + 1].dis > sta[i].dis + cmax * davg){
                printf("The maximum travel distance = %.2f", sta[i].dis + cmax * davg);
                return 0;
            }
            int j, minp = 0x3fffffff, no = -1;
            for (j = i + 1; sta[j].dis <= di + cmax * davg && sta[j].pri >= sta[i].pri; j++){
                if (sta[j].pri < minp){
                    minp = sta[j].pri;
                    no = sta[j];
                }
            }
            if (sta[j].dis <= sta[i].dis + cmax * davg){

            }
        }
    }
    return 0;

}
