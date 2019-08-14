#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> seq;
int n, p;
int main()
{
    scanf("%d %d", &n, &p);
    seq.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &seq[i]);
    }
    sort(seq.begin(), seq.end());
    int res = 1;
    for (int i = 0; i < n; i++){
        int j = i + res;
        while (j < n && seq[j] <= seq[i] * p) j++;
        if (j - i > res)
            res = j - i;
    }
    printf("%d", res);

    return 0;
}
