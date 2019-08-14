#include <iostream>
#include <vector>
using namespace std;

vector<int> digits;

bool isPrime(long long n){
    if (n == 1 || n == 0) return false;
    for (long long i = 2;i*i <= n;i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int l,k;
    scanf("%d %d",&l,&k);
    digits.resize(l);
    for (int i = 0;i < l;i++){
        scanf("%1d",&digits[i]);
    }
    for (int j = 0;j <= l- k;j++){
        long long sum = 0;
        for (int m = 0;m < k;m++)
            sum  = sum*10 + digits[j+m];
        if (isPrime(sum)){
            for (int i = 0;i < k;i++)
                printf("%d",digits[j+i]);
            return 0;
        }
    }
    printf("404");
    return 0;
}
