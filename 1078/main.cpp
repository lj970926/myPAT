#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;

bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int msize, n;
    scanf("%d %d", &msize, &n);
    while (!isPrime(msize)) msize++;
    h.resize(msize);
    fill(h.begin(), h.end(), -1);
    for (int i = 0; i < n; i++){
        if (i != 0)
            printf(" ");
        int t;
        scanf("%d", &t);
        int p = t % msize;
        int j;
        for (j = 0; j < h.size(); j++){
            if (h[p] == -1){
                h[p] = t;
                printf("%d", p);
                break;
            }
            p = (p + (j + 1 * j + 1)) % msize;
        }
        if (j >= h.size())
            printf("-");
    }
    return 0;
}
