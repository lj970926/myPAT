#include <iostream>
#include <stack>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int maxn = 100010;
int c[maxn];

void update(int x, int v){
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}

int getsum(int x){
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)){
        sum += c[i];
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    stack<int> s;
    for (int i = 0; i < n; i++){
        string op;
        cin >> op;
        if (op[1] == 'u'){
            int x;
            scanf("%d", &x);
            s.push(x);
            update(x, 1);
        }
        else if (op[1] == 'o'){
            if (!s.empty()){
                int x = s.top();
                s.pop();
                update(x, -1);
                printf("%d\n", x);
            }
            else
                printf("Invalid\n");

        }
        else{
            if (!s.empty()){
                int lo = 1, hi = maxn;
                int o = (s.size() + 1) / 2;
                while (lo < hi){
                    int mid = lo + (hi - lo) / 2;
                    if (getsum(mid) >= o)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                printf("%d\n", lo);

            }
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
