#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct Customer{
    int arrivetime;int processtime;
    Customer(int a, int p):arrivetime(a), processtime(p){};
};
struct Event{
    int cid;int type;int occurtime;
    Event(int c,int t, int o):cid(c),type(t),occurtime(o){};
};
int n, k,totaltime = 0;
vector<Event> events;
vector<Customer> cus;
bool cmp(const Event &a, const Event &b);
void arrive(Event e,queue<int> *q);
void leave(Event e,queue<int> *q);
int main()
{
    cin >> n >> k;
    queue<int> *q = new queue<int> [k+1];
    for (int i =0;i < n;i++){
        int hh, mm, ss, ptime;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&ptime);
        if (hh >= 17&&!((mm == 0)&&(ss == 0)))
            continue;
        cus.push_back(Customer(hh*3600 + mm * 60 + ss,ptime*60));
    }
    for (int i = 0;i < cus.size();i++)
        events.push_back(Event(i,0,cus[i].arrivetime));
    sort(events.begin(), events.end(),cmp);
    for (int i = 0;i < events.size();i++){
        if(events[i].occurtime < 8*3600){
            totaltime += (8*3600-events[i].occurtime);
            events[i].occurtime = 8*3600;
        }
    }
    for (int i = 0;i < events.size();i++){
        if (events[i].type == 0)
            arrive(events[i],q);
        else
            leave(events[i],q);
    }
    float averagetime;
    if (cus.size() == 0)
        averagetime = 0.0;
    else
        averagetime = (float)totaltime/60/cus.size();
    printf("%.1f",averagetime);
    return 0;
}

bool cmp(const Event &a, const Event &b){
    return (a.occurtime < b.occurtime? true : false);
}

void arrive(Event e,queue<int> *q){
    int minq = 1;
    for (int i = 2;i < k+1;i++){
        if (q[i].size() < q[minq].size())
            minq = i;
    }
    if (q[minq].empty()){
        events.push_back(Event(e.cid,minq,e.occurtime + cus[e.cid].processtime));
        sort(events.begin(), events.end(),cmp);
        q[minq].push(e.cid);
    }
    else
        q[0].push(e.cid);

}
void leave(Event e,queue<int> *q){
    int qnum = e.type;
    q[qnum].pop();
    if (!q[0].empty()){
        int temp = q[0].front();
        q[qnum].push(temp);
        events.push_back(Event(temp,qnum,e.occurtime + cus[temp].processtime));
        totaltime += (e.occurtime - cus[temp].arrivetime);
        sort(events.begin(), events.end(),cmp);
        q[0].pop();
    }

}
