#include <iostream>
#include <vector>
using namespace std;
vector<int> post, in;
vector<vector<int> > tre(35);

void create(int ii, int ij, int pi, int pj, int index){
    if (ii > ij)
        return;
    int i;
    for (i = ii; in[i] != post[pj]; i++) ;
    int r = post[pj], ll = i - ii - 1, lr = ij - i - 1;
    tre[index].push_back(r);
    create(ii, i - 1, pi, pi + ll, index + 1);
    create(i + 1, ij, pj - lr - 1, pj - 1, index + 1);

}

int main()
{
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    create(0, n - 1, 0, n - 1, 0);
    bool flag = true;
    for (int i = 0; i < tre.size(); i++){
        if (i % 2 == 0){
            for (int j = tre[i].size() - 1; j >= 0; j--){
                flag? flag = false : printf(" ");
                printf("%d", tre[i][j]);
            }
        }
        else{
            for (int j = 0; j < tre[i].size(); j++){
                flag? flag = false : printf(" ");
                printf("%d", tre[i][j]);
            }
        }
    }
    return 0;
}
