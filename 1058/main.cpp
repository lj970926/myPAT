#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int c;
    c = (a3 + b3) / 29;
    c3 = (a3 + b3) % 29;
    c2 = (a2 + b2 + c) % 17;
    c = (a2 + b2 + c) / 17;
    c1 = a1 + b1 + c;
    printf("%d.%d.%d", c1, c2, c3);
    return 0;
}
