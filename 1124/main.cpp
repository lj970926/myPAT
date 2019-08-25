#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> win;
int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    if (s <= n){
         int ns = s;
        for (int i = 1; i <= n; i++){
            string st;
            cin >> st;
            if (i >= ns && win.find(st) == win.end()){
                printf("%s\n", st.c_str());
                win.insert(st);
                ns = i + m;
            }
        }
    }
    else
        printf("Keep going...\n");
    return 0;
}
