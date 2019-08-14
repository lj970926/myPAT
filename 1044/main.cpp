#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> sum;
vector<int> result;
int n,m;

void findmin(int i, int &j, int &tempmin){
    int left = i,right = n;
    while(right  >  left){
        int mid = left + (right - left)/2;
        if ((sum[mid] - sum[i-1]) < m){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    j = left;
    tempmin = sum[j] - sum[i-1];
    if (tempmin < m)
        tempmin = INT_MAX;
    return;
}

int main(){
    scanf("%d %d",&n,&m);
    sum.resize(n+1);
    sum[0] = 0;
    for (int i = 1;i <=n;i++){
        scanf("%d",&sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = INT_MAX;
    for (int i = 1;i <= n;i++){
        int j,tempmin;
        findmin(i,j,tempmin);
        if (tempmin <= minans){
            if (tempmin < minans){
                result.clear();
                minans = tempmin;
            }
            result.push_back(i);
            result.push_back(j);
        }
    }
    printf("%d-%d",result[0],result[1]);
    for (int i = 2;i < result.size();i+=2){
        printf("\n%d-%d",result[i],result[i+1]);
    }
    return 0;
}
