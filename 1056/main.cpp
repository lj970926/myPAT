#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int mice[maxn], round[maxn], res[maxn];
int main()
{
    int np, ng;
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++)
        scanf("%d", &mice[i]);
    for (int i = 0; i < np; i++)
        scanf("%d", &round[i]);
    int cn = np;
    while(cn != 1){
        int turn = (cn + ng - 1) / ng + 1;
        for (int i = 0; i < cn; i++){
            if (i % ng == 0)
                round[i/ng] = round[i];
            else{
                int tnum = round[i], nnum = round[i/ng];
                if (mice[tnum] > mice[nnum]){
                    round[i/ng] = round[i];
                    res[nnum] = turn;
                }
                else{
                    res[tnum] = turn;
                }

            }
        }
        cn = (cn + ng - 1) / ng;
    }
    res[round[0]] = 1;
    for (int i = 0; i < np; i++){
        if (i != 0)
            printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}
