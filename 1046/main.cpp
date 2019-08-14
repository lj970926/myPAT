#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dis;
int main()
{
    int n,m;
    scanf("%d",&n);
    dis.resize(n+2);
    dis[1] = 0;
    for (int i = 1;i <= n;i++){
        scanf("%d",&dis[i+1]);
        dis[i+1] += dis[i];
    }
    scanf("%d",&m);
    bool first = true;
    for (int i = 0;i < m;i++){
        first?first = false:printf("\n");
        int s,d;
        scanf("%d %d",&s,&d);
        if (s > d){
            int t = s;
            s = d;
            d = t;
        }
        int tempdis = dis[d] - dis[s];
        printf("%d",min(tempdis,dis[n+1]-tempdis));
    }
    return 0;
}
