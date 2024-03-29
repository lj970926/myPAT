#include <iostream>
#include <vector>
using namespace std;
vector<int> seg;
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a = a + b;
    if (a == 0){
        printf("0\n");
        return 0;
    }
    if (a < 0){
        a = -a;
        printf("-");
    }
    while (a != 0){
        seg.push_back(a % 1000);
        a /= 1000;
    }
    printf("%d", seg[seg.size() - 1]);
    for (int i = seg.size() - 2; i >= 0; i--){
        printf(",%03d", seg[i]);
    }
    printf("\n");
    return 0;
}
