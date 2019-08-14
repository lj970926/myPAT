#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Use{
    int tsc, ps,id;
    Use():tsc(0), ps(0), id(-1){};
};
int mes[10010][6];
bool app[10010] = {false};
int p[6];
vector<Use> user;

bool cmp(Use a, Use b){
    return (a.tsc > b.tsc || (a.tsc == b.tsc && a.ps > b.ps) ||(a.tsc == b.tsc && a.ps == b.ps && a.id < b.id));
}

int main()
{
    int n, k, m;
    fill(mes[0], mes[0] + 10010 * 6, -1);
    scanf("%d %d %d", &n, &k, &m);
    user.resize(n + 1);
    for (int i = 1; i <= k; i++){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++){
        user[i].id = i;
    }
    for (int i = 0; i < m; i++){
        int uid, pid, sc;
        scanf("%d %d %d", &uid, &pid, &sc);
        if (sc != -1)
            app[uid] = true;
        if (mes[uid][pid] == -1)
            mes[uid][pid] = 0;
        if (sc > mes[uid][pid]){
            user[uid].tsc += (sc - mes[uid][pid]);
            mes[uid][pid] = sc;
            if (sc == p[pid])
                user[uid].ps++;
        }
    }
    sort(user.begin() + 1, user.end(), cmp);
    int r = 0, cnt = 1;
    for (int i = 1; i < user.size(); i++){
        if (user[i].id == -1 || !app[user[i].id])
            continue;
        if (r == 0||user[i].tsc != user[i-1].tsc)
            r = cnt;
        printf("%d %05d %d", r, user[i].id, user[i].tsc);
        for (int j = 1; j <= k; j++){
            if (mes[user[i].id][j] == -1)
                printf(" -");
            else
                printf(" %d", mes[user[i].id][j]);
        }
        printf("\n");
        cnt++;
    }
    return 0;
}
