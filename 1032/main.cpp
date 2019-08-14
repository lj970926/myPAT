#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

struct Lnode{
    int next;int visited = 0;
};

int main()
{
    int p1,p2,n;
    cin >> p1 >> p2 >> n;
    if (p1 == p2){
        printf("%05d",p1);
        return 0;
    }
    map<int,Lnode> lists;
    for (int i = 0;i < n;i++){
        Lnode temp;
        int tad;
        char data;
        cin >> tad >> data >> temp.next;
        lists[tad] = temp;
    }
    while(p1 != -1&&p2 != -1){
        if (lists[p1].visited){
            printf("%05d",p1);
            return 0;
        }
        else if (lists[p2].visited){
            printf("%05d",p2);
            return 0;
        }
        else{
            lists[p1].visited = lists[p2].visited = 1;
            p1 = lists[p1].next; p2 = lists[p2].next;
        }
    }
    while(p1 != -1){
        if (lists[p1].visited){
            printf("%05d",p1);
            return 0;
        }
        else
            p1 = lists[p1].next;
    }
    while (p2 != -1){
        if (lists[p2].visited){
            printf("%05d",p2);
            return 0;
        }
        else
            p2 = lists[p2].next;
    }
    cout << -1;
    return 0;
}
