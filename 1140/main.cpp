#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
int main()
{
    int d, n;
    scanf("%d %d", &d, &n);
    num.push_back(d);
    for (int i = 0; i < n - 1; i++){
        vector<int> ne;
        int j = 0;
        while (j < num.size()){
            int p;
            for (p = j + 1; p < num.size() && num[p] == num[j]; p++) ;
            ne.push_back(num[j]);
            ne.push_back(p - j);
            j = p;
        }
        num = ne;
    }
    for (int i = 0; i < num.size(); i++){
        printf("%d", num[i]);
    }
    return 0;
}
