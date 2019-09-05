#include <iostream>
#include <algorithm>
using namespace std;
struct Fraction{
    long long up = 0, down = 1;
};

long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction a){
    long long d = gcd(abs(a.up) , abs(a.down));
    if (a.down < 0){
        a.down = - a.down;
        a.up = - a.up;
    }
    a.up /= d;
    a.down /= d;
    return a;
}

Fraction add(Fraction a, Fraction b){
    Fraction ans;
    ans.down = a.down * b.down;
    ans.up = a.up * b.down + a.down * b.up;
    return reduction(ans);
}

void show(Fraction a){
    if (a.down == 1){
        printf("%lld\n", a.up);
    }
    else if (abs(a.up) > a.down){
        printf("%lld %lld/%lld\n", a.up / a.down, abs(a.up % a.down), a.down);
    }
    else{
        printf("%lld/%lld\n", a.up, a.down);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Fraction sum;
    for (int i = 0; i < n; i++){
        Fraction tmp;
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        sum = add(sum, tmp);
    }
    show(sum);
    return 0;
}
