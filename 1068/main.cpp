#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int maxn = 10005, maxm = 105;
int dp[maxm];
bool choice[maxn][maxm], flag[maxn] = {false};
vector<int> coins;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    scanf("%d %d", &n, &m);
    coins.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &coins[i]);
    sort(coins.begin() + 1, coins.end(), cmp);
    for (int i = 1; i <= n; i++){
        for (int v = m; v >= coins[i]; v--){
            if (dp[v] <= dp[v - coins[i]] + coins[i]) {
                choice[i][v] = true;
                dp[v] = dp[v - coins[i]] + coins[i];
            }
            else
                choice[i][v] = false;
        }
    }
    if (dp[m] == m){
        int k = n, v = m;
        while (k > 0){
            if (choice[k][v]){
                flag[k] = true;
                v -= coins[k];
            }
            k--;
        }
        bool f = true;
        for (int i = n; i > 0; i--){
            if (flag[i]){
                f ? f = false : printf(" ");
                printf("%d", coins[i]);
            }
        }
    }
    else
        printf("No Solution");
    return 0;


}
