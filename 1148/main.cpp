#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> state;
int n;
bool judge(int i, int j){
    vector<bool> iswolf(n + 1, false);
    iswolf[i] = true;
    iswolf[j] = true;
    bool flag = false;
    int num = 0;
    for (int k = 1; k <= n; k++){
        if ((state[k] > 0 && iswolf[state[k]]) ||(state[k] < 0 && !iswolf[abs(state[k])])){
            num++;
            if (k == i || k == j){
                if (flag)
                    return false;
                flag = true;
            }
        }
    }
    if (flag && num == 2)
        return true;
    return false;
}

int main()
{

    scanf("%d", &n);
    state.resize(n + 1);
    for (int i = 1; i <= n; i++){
        scanf("%d", &state[i]);
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (judge(i, j)){
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
