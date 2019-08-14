#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> digits;
vector<long long> pos;
int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0){
        digits.push_back(n%10);
        n /= 10;
    }
    pos.resize(digits.size());
    digits[1] = 1;
    int w = 10;
    for (int i = 2;i < digits.size();i++){
        digits[i] = 10*pos[i-1] + w;
        w *= 10;
    }
    long long total = 0;
    for (int i = 0;i < digits.size();i++){
        if (digits[i] == 1){
            total += (pos[i] + )
        }
    }
    printf("%d",total);
    return 0;
}
