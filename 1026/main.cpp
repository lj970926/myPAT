#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 10000+5;
const int CLOSE_TIME = 21*3600;

struct Customer{
    int atime,ptime,vip,stime;
    Customer(int a,int p, int v):atime(a),ptime(p),vip(v),stime(INT_MAX){};
};

struct Table{
    int ftime = 0;
    bool vip = false;
    int times=0;
};

bool cmp(Customer &a,Customer &b){
    return a.atime < b.atime;
}

bool cmp2(Customer &a, Customer &b){
    return a.stime < b.stime;
}

int main()
{
    int n,k,m;
    vector<Customer> customers;
    cin >> n;
    for (int i = 0;i < n;i++){
        int h,m,s,v,p;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&p,&v);
        customers.push_back(Customer(h*3600+m*60+s,p,v));
    }
    cin >> k >> m;
    vector<Table> tables(k+5);
    for (int i = 0;i < m;i++){
        int temp;
        cin >> temp;
        tables[temp].vip = true;
    }
    sort(customers.begin(),customers.end(),cmp);
    //for (int i = 0;i < customers.size();i++) printf("%d\n",customers[i].atime);
    //bool result = tables[2].vip;
    int nextvip,curcus = 0;
    for (nextvip =0;customers[nextvip].vip == 0;nextvip++) ;
    for (int time = customers[0].atime;time < CLOSE_TIME&&curcus < customers.size();time++){
        for (int j = 1;j <= k;j++)
            if (tables[j].ftime <= time){
                if (tables[j].vip){
                    if (nextvip < customers.size()&&time >= customers[nextvip].atime){
                        customers[nextvip].stime = time;
                        tables[j].ftime = (customers[nextvip].ptime*60) + time;
                        tables[j].times++;
                        while(!customers[++nextvip].vip) ;
                        continue;
                    }
                }
                while (customers[curcus].vip&&curcus <nextvip) curcus++;
                if (curcus < customers.size()&&time >= customers[curcus].atime){
                    customers[curcus].stime = time;
                    tables[j].ftime = (customers[curcus].ptime*60) + time;
                    tables[j].times++;
                    curcus++;
                }
            }
    }
    sort(customers.begin(),customers.end(),cmp2);
    int cnt = 0;
    while (cnt < customers.size()&&customers[cnt].stime < INT_MAX) cnt++;
    for (int i = 0;i < cnt;i++){
        int ah,am,as,sh,sm,ss,wt;
        ah = customers[i].atime/3600;am = customers[i].atime%3600/60;as = customers[i].atime%60;
        sh = customers[i].stime/3600;sm = customers[i].stime%3600/60;ss = customers[i].stime%60;
        wt = (int)((double)(customers[i].stime - customers[i].atime)/60 + 0.5);
        printf("%02d:%02d:%02d %2d:%02d:%02d %d\n",ah,am,as,sh,sm,ss,wt);
    }
    bool first = true;
    for (int j = 1;j <= k;j++){
        if (first)
            first = false;
        else
            printf(" ");
        printf("%d",tables[j].times);
    }




    return 0;
}
