#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int pos[100005];
int main()
{
    int n;
    scanf("%d",&n);
    int finish = 0,ans = 0,k = 1;
    for (int i = 0;i < n;i ++){
        int num;
        scanf("%d",&num);
        pos[num] = i;
        if (num == i && num != 0)       //这里的finish统计的是除了0外到位的元素,故num!=0
            finish++;
    }

    while(finish < n-1){
        if (pos[0] == 0){
            while(pos[k] == k) k++;
            swap(pos[0],pos[k]);
            ans++;
        }
        else{
            swap(pos[0],pos[pos[0]]);
            ans++;
            finish++;
        }
    }
    printf("%d",ans);
    return 0;
}
