#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 0x3fffffff;
struct Station{
    double price;
    double dis;
    Station(double p, double d):price(p), dis(d){};
};

bool cmp(Station a, Station b){
    return a.dis < b.dis;
}

vector<Station> sta;
int main(){
    int cap, ds, dpu, n;
    scanf("%d %d %d %d", &cap, &ds, &dpu, &n);
    for (int i = 0; i < n; i++){
        double d;
        double p;
        scanf("%lf %lf", &p, &d);
        sta.push_back(Station(p, d));
    }
    sta.push_back(Station(inf, ds));
    sort(sta.begin(), sta.end(), cmp);
    if (sta[0].dis != 0.0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int index = 0;
    double sum = 0.0, tank = 0.0;
    while (1){
        if (sta[index + 1].dis - sta[index].dis > cap * dpu){
            printf("The maximum travel distance = %.2f\n", sta[index].dis + cap * dpu);
            return 0;
        }
        int minp = index + 1, i;
        for (i = index + 1; i < n + 1 && (sta[i].dis - sta[index].dis) <= cap * dpu ; i++){
            if (sta[i].price < sta[index].price){
                minp = i;
                break;
            }
            if (sta[i].price < sta[minp].price)
                minp = i;
        }
        if (sta[minp].price >= sta[index].price){
            if (i >= n + 1){
                sum += (((ds - sta[index].dis)) / dpu - tank) * sta[index].price;
                break;
            }
            sum += (cap - tank) * sta[index].price;
            tank = cap - (sta[minp].dis - sta[index].dis) / dpu;
        }
        else{
            sum += ((sta[minp].dis - sta[index].dis) / dpu - tank) * sta[index].price;
            tank = 0.0;
        }
        index = minp;
    }
    printf("%.2f", sum);
    return 0;

}
