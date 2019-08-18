#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cus{
    int arr, pro;
    Cus(int a, int p):arr(a), pro(p){};
};

const int op = 8 * 60 * 60;
const int clo = 17 * 60 * 60;

bool cmp(Cus a, Cus b){
    return a.arr < b.arr;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> wind(k, op);
    vector<Cus> cus;
    for (int i = 0; i < n; i++){
        int hh, mm, ss, p;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        int t = hh * 60 * 60 + mm * 60 + ss;
        if (t <= clo)
            cus.push_back(Cus(t, p * 60));
    }
    sort(cus.begin(), cus.end(), cmp);
    int sum = 0;
    for (int i = 0; i < cus.size(); i++){
        int mint = 0;
        for (int j = 1; j < k; j++){
            if (wind[j] < wind[mint])
                mint = j;
        }
        int st = max(wind[mint], cus[i].arr);
        sum += (st - cus[i].arr);
        wind[mint] = st + cus[i].pro;
    }
    double ans = (double)sum / cus.size() / 60;
    printf("%.1f", ans);
}
