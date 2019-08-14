#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int p,k;
    Node(int p_, int k_):p(p_), k(k_){};
};
vector<int> prime;
vector<Node> res;
bool isPrime(int n){
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n,tn;
    scanf("%d", &n);
    if (n == 1){
        printf("1=1");
        return 0;
    }

    tn = n;
    for (int i = 2; i <= n; i++){
        int k = 0;
        while(n % i == 0 && isPrime(i)){
            k++;
            n /= i;
        }
        if (k != 0)
            res.push_back(Node(i, k));
        if (n == 1)
            break;
    }
    printf("%d=",tn);
    for (int i = 0; i < res.size(); i++){
        if (i != 0)
            printf("*");
        if (res[i].k == 1)
            printf("%d", res[i].p);
        else
            printf("%d^%d",res[i].p, res[i].k);
    }
    return 0;
}
