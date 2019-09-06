#include <iostream>
#include <string>
using namespace std;
bool isPrime(int x){
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
    int n, k;
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    for (int i = 0; i <= n - k; i++){
        if (isPrime(stoi(s.substr(i, k)))){
            printf("%s\n", s.substr(i, k).c_str());
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
