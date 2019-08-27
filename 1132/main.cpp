#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string z;
        cin >> z;
        int len = z.size() / 2;
        string fz = z.substr(0, len), lz = z.substr(len, len);
        long long a = stoi(z), b = stoi(fz), c = stoi(lz);
        if (b * c != 0 && a % (b * c) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
