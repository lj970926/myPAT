#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
bool isprime(int a);
int reverse_sum(const vector<int> &a,int b);
int main()
{
    while(1){
        int n,b;
        scanf("%d",&n);
        if (n < 0)
            break;
        scanf("%d",&b);
        vector<int> a;
        int temp = n;
        while(temp != 0){
            a.push_back(temp%b);
            temp /= b;
        }
        int rn = reverse_sum(a,b);
        if (isprime(n)&&isprime(rn))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
bool isprime(int a){
    if (a<=1)
        return false;
    for (long i = 2;i < a;i++){
        if (a%2 == 0){
            return false;
        }
    }
    return true;
}
int reverse_sum(const vector<int> &a,int b){
    int sum = 0;
    for (int i = 0; i < a.size();i++){
        int weight = a.size()-1-i;
        sum += (a[i]*pow(b,weight));
    }
    return sum;
}
