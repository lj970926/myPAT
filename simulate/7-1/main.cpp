#include <iostream>
using namespace std;
bool isprime(int x){
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
    int n;
    scanf("%d", &n);
    int tn = n;
    while(!(isprime(n) && (isprime(n - 6) || isprime(n + 6)))){
        n++;
    }
    if (tn == n){
        printf("Yes\n");
        printf("%d\n", isprime(n - 6) ? n - 6: n + 6);
    }
    else{
        printf("No\n");
        printf("%d\n", n);
    }

    return 0;
}
