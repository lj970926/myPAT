#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> tres;

void  uajust(int low, int high){
    int i = low, j = 2*i;
    while (j <= high){
        if (j+1 <= high && tres[j+1] > tres[j]){
                j = j+1;
        }
        if (tres[i] < tres[j]){
            swap(tres[i],tres[j]);
            i = j;
            j = 2 * i;
        }else
            break;
    }
}

int main()
{
    scanf("%d", &n);
    tres.resize(n+1);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
    }
    for (int i = 1; i <= n;i++)
        scanf("%d", &tres[i]);
    if (tres[2] > tres[1]){
        printf("Insertion Sort\n");
        int j = 2;
        while (j <= n && tres[j] > tres[j-1]) j++;
        int i = 1;
        while(i < j && tres[i] < tres[j]) i++;
        int tmp = tres[j];
        for (int k = j-1;k >= i;k--)
            tres[k+1] = tres[k];
        tres[i] = tmp;
    }
    else{
        printf("Heap Sort\n");
        int i = 2;
        while (i <= n && tres[i] < tres[1]) i++;
        swap(tres[1],tres[--i]);
        uajust(1,--i);
    }
    for (int i = 1; i <= n; i++){
        if (i != 1)
            printf(" ");
        printf("%d", tres[i]);
    }
    return 0;
}
