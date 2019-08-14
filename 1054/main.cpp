#include <iostream>
#include <map>
using namespace std;
map<int, int> pixel;
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int p;
            scanf("%d", &p);
            if (pixel.find(p) != pixel.end()) {
                pixel[p]++;
            } else
                pixel[p] = 1;
        }
    }
    int sp = -1, pnum = 0;
    for (auto itr = pixel.begin();itr != pixel.end(); itr++){
        if ((*itr).second > pnum){
            pnum = itr->second;
            sp = itr->first;
        }
    }
    printf("%d", sp);
    return 0;
}
