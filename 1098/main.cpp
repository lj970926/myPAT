#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, b;

void downAdjust(vector<int> &a, int lo, int hi){
    int i = lo, j = i * 2;
    while(j <= hi){
        if (j + 1 <= hi && a[j + 1] > a[j]) j = j + 1;
        if (a[i] > a[j]) break;
        swap(a[i], a[j]);
        i = j;
        j = j * 2;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int p;
    for (p = 2; p <= n && b[p] >= b[p - 1]; p++) ;
    int index = p;
    while (p <= n && b[p] == a[p]) p++;
    if (p == n + 1){
        printf("Insertion Sort\n");
        sort(b.begin() + 1, b.begin() + 1 + index);
    }
    else{
        printf("Heap Sort\n");
        int high;
        for (high = n; high > 2&& b[high] > b[1]; high--) ;
        swap(b[1], b[high--]);
        downAdjust(b, 1, high);
    }
    for (int i = 1; i < b.size(); i++){
        if (i != 1)
            printf(" ");
        printf("%d", b[i]);
    }
    return 0;
}
