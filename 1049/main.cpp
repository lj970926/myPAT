#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long num[12];
int main()
{
    long long n, rm = 0, m = 1, r = 1;
    cin >> n;
    num[0] = 0;
    for (int i = 1; i <=11; i++){
        num[i] = num[i - 1] * 10 + m;
        m *= 10;
    }
    m = 1;
    long long sum = 0;
    while (n != 0){
        int d = n % 10;
        if (d == 1){
            sum += (rm + num[r - 1] + 1);
        }
        else if (d != 0)
            sum += (num[r - 1] * d + m);
        rm = m * d + rm;
        m *= 10;
        r++;
        n /= 10;
    }
    printf("%lld", sum);
    return 0;
}
