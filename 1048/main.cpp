#include <iostream>
using namespace std;
int coins[5000];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        coins[t]++;
    }
    for (int i = 1; i <= m / 2; i++){
        if (coins[i] != 0){
            coins[i]--;
            if (coins[m - i] != 0){
                printf("%d %d\n", i, m - i);
                return 0;
            }
            coins[i]++;
        }
    }
    printf("No Solution\n");
    return 0;
}
