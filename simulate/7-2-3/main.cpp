#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tsize, m, n;
vector<int> h;

void ins(int x){
    int p = x % m;
    for (int i = 0; i < tsize; i++){
        if (h[(p + i) % tsize] == -1){
            h[(p + i) % tsize] = x;
            break;
        }
    }

}

int main()
{
    scanf("%d %d %d", &tsize, &m, &n);
    h.resize(tsize);
    fill(h.begin(), h.end(), -1);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        ins(t);
    }
    int sum = 0;
    for (int i = 0; i < m; i++){
        int j;
        for (j = 0; j < tsize && h[(i + j) % tsize] != -1; j++) ;
        sum += j + 1;
    }
    double ans = double(sum) / m;
    printf("%.1f\n", ans);
    return 0;
}
