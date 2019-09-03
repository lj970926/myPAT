#include <iostream>
#include <vector>
using namespace std;
vector<int> order(55), ans(55), tmp(55);
char prefix[6] = {"SHCDJ"};
int main(){
    int k;
    scanf("%d", &k);
    for (int i = 1; i < 55; i++)
        scanf("%d", &order[i]);
    for (int i = 1; i < 55; i++){
        ans[i] = i;
    }
    for (int i = 0; i < k; i++){
        for (int j = 1; j < 55; j++){
            tmp[order[j]] = ans[j];
        }
        ans = tmp;
    }
    for (int i = 1; i < 55; i++){
        char c = prefix[(ans[i] - 1) / 13];
        int n = (ans[i] - 1) % 13 + 1;
        if (i != 1)
            printf(" ");
        printf("%c%d", c, n);
    }
    printf("\n");

}
