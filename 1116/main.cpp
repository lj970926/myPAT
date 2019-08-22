#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10005;
bool isprime[maxn] = {false};
int r[maxn];
bool h[maxn] = {false};
void init(){
    for (int i = 2; i < maxn; i++){
        if (!isprime[i]){
            for (int j = 2; i * j < maxn; j++)
                isprime[i * j] = true;
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        r[t] = i + 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int q;
        scanf("%d", &q);
        printf("%04d: ", q);
        if (r[q] == 0)
            printf("Are you kidding?\n");
        else if (h[q])
            printf("Checked\n");
        else if (r[q] == 1)
            printf("Mystery Award\n");
        else if (!isprime[r[q]])
            printf("Minion\n");
        else
            printf("Chocolate\n");
        h[q] = true;
    }
    return 0;
}
