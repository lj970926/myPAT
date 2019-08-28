#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
int main()
{
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    int i = 0, j = n, p = 0, q = n;
    while (1){
        if (j - i == 1){
            printf("%d", pre[i]);
            return 0;
        }
        int m;
        for (m = p; in[m] != pre[i]; m++) ;
        if (m != p){
            q = m;
            j = i + m - p + 1;
            i++;
        }
        else{
            i = i + m - p + 1;
            p = m + 1;
        }

    }
    return 0;
}
