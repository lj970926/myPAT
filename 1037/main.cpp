#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> cou, pro;
int main(){
    int nc, np;
    scanf("%d", &nc);
    cou.resize(nc);
    for (int  i = 0; i < nc; i++){
        scanf("%lld", &cou[i]);
    }
    scanf("%d", &np);
    pro.resize(np);
    for (int i = 0; i < np; i++){
        scanf("%lld", &pro[i]);
    }
    sort(cou.begin(), cou.end());
    sort(pro.begin(), pro.end());
    long long sum = 0;
    int len = min(cou.size(), pro.size());
    for (int i = 0; i < len && cou[i] < 0 && pro[i] < 0; i++){
        sum += pro[i] * cou[i];
    }
    for (int i = 1; i <= len && cou[cou.size() - i] > 0 && pro[pro.size() - i] > 0; i++){
        sum += cou[cou.size() - i] * pro[pro.size() - i];
    }
    printf("%lld\n", sum);
    return 0;
}
