#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
bool h[100000] = {false};
int coup[100000], gue[10000];
set<int> sing;
int main()
{
    fill(coup, coup + 100000, -1);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        coup[t1] = t2;
        coup[t2] = t1;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int t;
        scanf("%d", &t);
        h[t] = true;
        gue[i] = t;
    }
    for (int i = 0; i < m; i++){
        int c = coup[gue[i]];
        if (c == -1 || !h[c]){
            sing.insert(gue[i]);
        }
    }
    printf("%d\n", sing.size());
    for (auto it = sing.begin(); it != sing.end(); it++){
        if (it != sing.begin())
            printf(" ");
        printf("%05d", *it);
    }
    return 0;
}
