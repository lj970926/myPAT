#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n, len = 0, lo = 0, hi = 0;
    cin >> n;
    int maxn = sqrt(n) + 1;
    int i = 2;
    while(i <= maxn){
        int j, temp = 1;
        for (j = i; j <= maxn; j++){
            temp *= j;
            if (n % temp != 0)
                break;
        }
        if (j - i > len){
            lo = i;
            hi = j;
            len = j - i;
        }
        i++;
    }
    if (len == 0){
        printf("%d\n%d", 1, n);
    }
    else{
        printf("%d\n", len);
        for (int i = lo; i < hi; i++){
            if (i != lo)
                printf("*");
            printf("%d", i);
        }
    }
    return 0;
}
