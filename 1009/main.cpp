#include <iostream>
#include <algorithm>
using namespace std;
double coe1[1005] = {0.0}, coe2[2005] = {0.0};
int ex1[15], ex2[125];

int main(){
    int k1;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++){
        int t;
        double c;
        scanf("%d %lf", &t, &c);
        ex1[i] = t;
        coe1[t] = c;
    }
    int k2;
    scanf("%d", &k2);
    int p = 0;
    for (int i = 0; i < k2; i++){
        int t;
        double c;
        scanf("%d %lf", &t, &c);
        for (int j = 0; j < k1; j++){
            int ne = t  +  ex1[j];
            double nc = coe1[ex1[j]] * c;
            if (coe2[ne] == 0.0)
                ex2[p++] = ne;
            coe2[ne] += nc;
        }
    }
    printf("%d", p);
    sort(ex2, ex2 + p);
    for (int i = p - 1; i >= 0; i--){
        printf(" %d %.1f", ex2[i], coe2[ex2[i]]);
    }
    return 0;
}
