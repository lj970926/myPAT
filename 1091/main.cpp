#include <iostream>
#include <queue>
using namespace std;

int m,n,l,t,ans = 0;
int slice[1300][130][65];
bool inq[1300][130][65] = {false};
int X[6] = {-1,1,0,0,0,0};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {0,0,0,0,1,-1};

struct Node{
    int x,y,z;
    Node(int tx, int ty, int tz):x(tx),y(ty),z(tz){};
};

bool judge(int x,int y, int z){
    if (x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < l
        && slice[x][y][z] == 1 && !inq[x][y][z])
            return true;
    return false;
}

void BFS(int x, int y, int z){
    queue<Node> q;
    q.push(Node(x,y,z));
    inq[x][y][z] = true;
    int tans = 1;
    while(!q.empty()){
        Node t = q.front();
        q.pop();
        for (int i = 0; i < 6;i++){
            int newx = t.x+X[i],newy = t.y + Y[i],newz = t.z+Z[i];
            if (judge(newx,newy,newz)){
                q.push(Node(newx, newy, newz));
                inq[newx][newy][newz] = true;
                tans++;
            }
        }
    }
    if (tans >= t)
        ans += tans;
}

int main()
{
    scanf("%d %d %d %d",&m,&n,&l,&t);
    for (int k = 0;k < l;k++)
        for (int i = 0;i < m;i++)
            for (int j = 0; j < n;j++)
                scanf("%d",&slice[i][j][k]);
    for (int k = 0;k < l;k++)
        for (int i = 0; i < m;i++)
            for (int j = 0;j < n;j++)
                if (slice[i][j][k] == 1&& !inq[i][j][k]){
                    BFS(i,j,k);
                }
    printf("%d",ans);
    return 0;
}
