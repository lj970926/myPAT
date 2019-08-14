#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int k;
    scanf("%d",&k);
    bool first = true;
    for (int i = 0;i < k;i++){
        int n;
        scanf("%d",&n);
        vector<int> seq(n);
        bool sol  = true;
        for (int j = 0;j < n;j++){
            scanf("%d",&seq[j]);
            if(sol){
                for (int p = 0;p < j;p++){
                    if ((seq[p] == seq[j])||(abs(seq[p]-seq[j])==abs(p-j))){
                        first?first = false:printf("\n");
                        printf("NO");
                        sol = false;
                        break;
                    }
                }
            }

        }
        if (sol){
            first?first = false:printf("\n");
            printf("YES");
        }
    }
    return 0;
}
