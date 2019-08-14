#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ori, tmp;
int n;
bool jug(vector<int> &a){
    for (int i = 0; i < a.size(); i++)
        if (a[i] != tmp[i])
            return false;
    return true;
}

bool ins(vector<int> a){
    bool flag = false;
    for (int j = 1;j < n; j++){
        if (jug(a))
            flag = true;
        int t = a[j];
        int i = 0;
        while(a[i] < a[j]) i++;
        for (int p = j - 1; p >= i; p--){
            a[p + 1] = a[p];
        }
        a[i] = t;
        if (flag && !jug(a)){
            printf("Insertion Sort\n");
            for (int i = 0; i < a.size(); i++){
                if (i != 0)
                    printf(" ");
                printf("%d", a[i]);
            }
            break;
        }
    }
    return flag;
}

void m(int lo, int len, vector<int> &a){
    if (lo + len >= n)
        return;
    vector<int> temp = a;
    int mid = lo + len;
    int hi = min(mid + len, n);
    int i = lo, j = mid, p = lo;
    while (i < mid && j < hi){
        if (a[i] < a[j])
            temp[p++] = a[i++];
        else
            temp[p++] = a[j++];
    }
    while (i < mid)
        temp[p++] = a[i++];
    while (j < hi)
        temp[p++] = a[j++];
    a = temp;
}

void Merg(vector<int> &a){
    bool flag = false;
    for (int len = 1; len < n; len *= 2){
        if (jug(a))
            flag = true;
        for (int j = 0;j < n; j += 2 * len)
            m(j,len,a);
        if (flag){
            printf("Merge Sort\n");
            for (int i = 0; i < a.size(); i++){
                if (i != 0)
                    printf(" ");
                printf("%d", a[i]);
            }
            break;
        }
    }

}

int main()
{

    scanf("%d", &n);
    ori.resize(n);
    tmp.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ori[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &tmp[i]);
    if (!ins(ori))
        Merg(ori);

    return 0;
}
