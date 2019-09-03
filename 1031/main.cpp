#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char G[40][40];
int y[3] = {0, 1, 0}, x[3] = {1, 0, -1};
int main(){
    string s;
    cin >> s;
    int n = s.size() + 2, n1 = n / 3, n2 = n / 3 + n % 3;
    fill(G[0], G[0] + 40 * 40, ' ');
    int tx = 0, ty = 0, p = 0;
    for (int i = 0; i < s.size(); i++){
        G[tx][ty] = s[i];
        if (tx + x[p] >= n1 || ty + y[p] >= n2 || tx + x[p] < 0 || ty + y[p] < 0)
            p++;
        tx = tx + x[p];
        ty = ty + y[p];
    }
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            printf("%c", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
