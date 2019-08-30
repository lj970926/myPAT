#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x){
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int msize, n, m;
    scanf("%d %d %d", &msize, &n, &m);
    while (!isPrime(msize)) msize++;
    vector<int> h(msize, -1);
    for (int i = 0; i < n; i++){
        int ke;
        scanf("%d", &ke);
        int j;
        for (j = 0; j <= msize; j++){
            int pos = (ke + j * j) % msize;
            if (h[pos] == -1){
                h[pos] = ke;
                break;
            }
        }
        if (j > msize){
            printf("%d cannot be inserted.\n", ke);
        }
    }
    long long sum = 0;
    for (int i = 0; i < m; i++){
        int q;
        scanf("%d", &q);
        long long cnt = 0;
        for (int j = 0; j <= msize; j++){
            cnt++;
            int p = (q + j * j) % msize;
            if (h[p] == q || h[p] == -1)
                break;
        }
        sum += cnt;
    }
    double ans = double(sum) / m;
    printf("%.1f\n",ans);
    return 0;
}
