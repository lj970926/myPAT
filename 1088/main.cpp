#include <iostream>
#include <algorithm>
using namespace std;
struct Frac{
    long long up, down;
};

char al[4] = {'+', '-', '*', '/'};

long long gcd(long long a, long long b){
    return b == 0? a : gcd(b, a % b);
}

Frac reduc(Frac a){
    if (a.down < 0){
        a.up = - a.up;
        a.down = -a.down;
    }
    int d = gcd(abs(a.up), abs(a.down));
    a.up /= d;
    a.down /= d;
    return a;
}

void show(Frac a){
    a = reduc(a);
    if (a.down == 0){
        printf("Inf");
        return;
    }
    if (a.down == 1){
        if (a.up < 0)
            printf("(%lld)", a.up);
        else
            printf("%lld", a.up);
    }

    else if (abs(a.up) > abs(a.down)){
        if (a.up < 0 || a.down < 0){
            printf("(%lld %lld/%lld)", a.up / a.down, abs(a.up) % a.down, a.down);
        }
        else{
            printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
        }
    }
    else{
        if (a.up < 0)
            printf("(%lld/%lld)", a.up, a.down);
        else
            printf("%lld/%lld", a.up, a.down);
    }
}

Frac add(Frac a, Frac b){
    Frac res;
    res.down = a.down* b.down;
    res.up = a.up * b.down + a.down * b.up;
    return reduc(res);
}

Frac diff(Frac a, Frac b){
    Frac res;
    res.down = a.down * b.down;
    res.up = a.up * b.down - b.up * a.down;
    return reduc(res);
}

Frac prod(Frac a, Frac b){
    Frac res;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    return reduc(res);
}

Frac quot(Frac a, Frac b){
    Frac res;
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    return reduc(res);
}

void ashow(Frac a, Frac b, Frac c, int m){
    show(reduc(a));
    printf(" %c ", al[m]);
    show(reduc(b));
    printf(" = ");
    show(reduc(c));
    printf("\n");
}

int main()
{
    Frac a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    ashow(a,b,add(a,b),0);
    ashow(a,b,diff(a,b),1);
    ashow(a,b,prod(a,b),2);
    ashow(a,b,quot(a,b),3);
    return 0;
}
