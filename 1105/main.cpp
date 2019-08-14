#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> dig;
int d[10005][10005] = {0};
int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int num;
    scanf("%d", &num);
    int m,n;
    for (int i = sqrt(num); i >= 1; i--){
        if (num % i == 0){
            n = i;
            m = num / i;
            break;
        }
    }
    for (int i = 0; i < num; i++){
        int t;
        scanf("%d", &t);
        dig.push_back(t);
    }
    sort(dig.begin(), dig.end(), cmp);
    int i = 0, p = 0, tx = 0, ty = 0;
    while(p < num){
        d[tx][ty] = dig[p++];
        if (tx + x[i] < 0 || ty + y[i] < 0 || tx + x[i] >= m || ty + y[i] >= n || d[tx + x[i]][ty + y[i]] != 0)
            i = (i + 1) % 4;
        tx = tx + x[i];
        ty = ty + y[i];

    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j != 0)
                printf(" ");
            printf("%d", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
