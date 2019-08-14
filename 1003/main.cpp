#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef enum{WHITE,GRAY,BLACK} VStatus;
struct Vertex{
    VStatus status;
    int data;
    int priority;
    int dTime;
    Vertex(int d):status(WHITE),data(d),priority(INT_MAX),dTime(0){};
};

struct Edge{
    int weight;
    int next;
    Edge(int w, int n):weight(w),next(n){};
};
int find_Max(int s,int d,vector<list<Edge> >&E,vector<Vertex> &V);
int main(){
    int N,M,s,d;
    vector<Vertex> V;
    vector <int> history;
    vector<list<Edge> > E(10000);

    cin >> N;
    cin >> M;
    cin >> s;
    cin >> d;
    int temp;
    for (int i = 0;i < N;i++){
        cin >> temp;
        V.push_back(Vertex(temp));
    }
    int temp_u,temp_v,temp_w;
    for (int i = 0; i < M;i++){
        cin >> temp_u;
        cin >> temp_v;
        cin >> temp_w;
        E[temp_u].push_back(Edge(temp_w,temp_v));
    }
    int w = s;
    V[s].priority = 0;
    while (1){
        for (list<Edge>::iterator itr = E[w].begin();itr != E[w].end();itr++){
            temp = (*itr).next;
            if (V[temp].status == WHITE)
                if (V[temp].priority > V[w].priority + (*itr).weight)
                    V[temp].priority = V[w].priority + (*itr).weight;
        }
        V[w].status = BLACK;
        int shortest = INT_MAX;
        for (int i = 0;i < N;i++){
            if (V[i].status == WHITE)
                if (V[i].priority < shortest){
                    shortest = V[i].priority;
                    w = i;
                }

        }
        if (V[w].status == BLACK)
            break;
    }
    cout << V[d].priority << ' ';

    for (int i = 0;i < N;i++){
        V[i].status = WHITE;
        V[i].priority = 0;
    }
   int sum = find_Max(s,d,E,V);
    cout  << sum;

}
int find_Max(int s,int d,vector<list<Edge> >&E,vector<Vertex> &V){
    vector<int> history;
    if (d == s)
        return V[s].data;
    int temp;
    for (int i = 0;i < V.size();i++){
        for (list<Edge>::iterator itr = E[i].begin();itr != E[i].end();itr++){
            temp = (*itr).next;
            if (temp == d){
                history.push_back(find_Max(s,i,E,V) + V[d].data);
            }
        }
    }
    int maxi = -1;
    for (int i = 0;i < history.size();i++){
        if (maxi < history[i])
            maxi = history[i];
    }
    return maxi;

}
bool have_loop{
    int
}
void dfs(int s,int &time){
    int temp;
    V[s].status = GRAY;
    V[s].dTime = ++time;
    for (list<Edge>::iterator itr =E[s].begin();itr != E[s].end();itr++){
        temp = (*itr).next;
        if (V[temp].status == WHITE){
             dfs(temp,time);
        }
        else if (V[temp].status == GRAY){

        }
        else{
            if (V[temp].dTime > V[s].dTime)
                ;
            else
                ;
        }

    }
}
