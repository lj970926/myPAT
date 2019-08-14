#include <iostream>
#include <algorithm>
using namespace std;
struct Fraction{
    long long up, down;
};

long long gcd(long long a, long long b){
    return b == 0? a : gcd(b, a % b);
}

Fraction add(Fraction a, Fraction b){
    Fraction result;
    result.down = a.down * b.down;
    result.up = a.up * b.down + b.up * a.down;
    int d = gcd(abs(result.up), abs(result.down));
    result.up /= d;
    result.down /= d;
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    Fraction sum;
    sum.up = 0;
    sum.down = 1;
    for (int i = 0; i < n; i++){
        Fraction a;
        scanf("%lld/%lld", &a.up, &a.down);
        sum = add(sum, a);
    }
    if (sum.down == 1)
        printf("%lld", sum.up);
    else if (abs(sum.up) > sum.down){
        printf("%lld %lld/%lld", sum.up / sum.down, abs(sum.up) % sum.down, sum.down);
    }
    else
        printf("%lld/%lld", sum.up, sum.down);
    return 0;
}
