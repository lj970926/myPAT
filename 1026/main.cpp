#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int op = 8* 3600, clo = 21*3600;
const int inf = 999999999;
struct Peo{
    int arr, pro, st = clo + 1, vip;
    Peo(int a, int p, int v):arr(a), pro(p), vip(v){};
};
struct Tab{
    int num = 0,vip = 0,fin = 8 * 3600;
};
vector<Tab> table;
vector<Peo> player;

bool cmp1(Peo a, Peo b){
    return a.arr < b.arr;
}

bool cmp2(Peo a, Peo b){
    return a.st < b.st;
}

int findnextvip(int vid){
    for (vid++; vid < player.size() && player[vid].vip != 1; vid++) ;
    return vid;
}

void alloc(int tid, int pid){
    player[pid].st = max(table[tid].fin, player[pid].arr);
    table[tid].fin = player[pid].st + player[pid].pro;
    table[tid].num++;
}

void showT(int time){
    int s = time % 60, m = time / 60 % 60, h = time/3600;
    printf("%02d:%02d:%02d", h, m, s);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int h, m, s, p, ta;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &ta);
        int t = h * 3600 + m * 60 + s;
        if (t > clo)
            continue;
        p = (p <= 120 ? p * 60 : 7200);
        player.push_back(Peo(t, p, ta));
    }
    int k, m;
    scanf("%d %d", &k, &m);
    table.resize(k + 1);
    for (int i = 0; i < m; i++){
        int v;
        scanf("%d", &v);
        table[v].vip = 1;
    }
    sort(player.begin(), player.end(), cmp1);
    int vid = -1;
    vid = findnextvip(vid);
    for (int i = 0; i < player.size(); i++){
        if (player[i].vip == 1 && i < vid)
            continue;
        int index = 0, minf = inf;
        for (int j = 1; j <= k; j++){
            if (table[j].fin < minf){
                index = j;
                minf = table[j].fin;
            }
        }
        if (minf >= clo)
            break;
        if (table[index].vip == 1 && player[i].vip == 1){
            alloc(index, i);
            vid = findnextvip(vid);
        }
        else if (table[index].vip == 1 && player[i].vip == 0){
            if (vid < player.size() && table[index].fin >= player[vid].arr){
                alloc(index, vid);
                vid = findnextvip(vid);
                i--;
            }
            else
                alloc(index, i);
        }
        else if (table[index].vip == 0 && player[i].vip == 1){
            int vipind = 0, minvf = inf;
            for (int j = 1; j <= k; j++){
                if (table[j].vip == 1 && table[j].fin < minvf){
                    vipind = j;
                    minvf = table[j].fin;
                }
            }
            if (minvf <= player[i].arr)
                alloc(vipind, i);
            else
                alloc(index, i);
            vid = findnextvip(vid);
        }
        else{
            alloc(index, i);
        }
    }
    sort(player.begin(), player.end(), cmp2);
    for (int i = 0; i < player.size() && player[i].st < clo; i++){
        showT(player[i].arr);
        printf(" ");
        showT(player[i].st);
        printf(" %.0f\n", round((player[i].st - player[i].arr)/60.0));
    }
    for (int i = 1; i <= k; i++){
        if (i != 1)
            printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}
