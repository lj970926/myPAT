#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string> > courses;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    courses.resize(m+1);
    for (int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        int c;
        scanf("%d",&c);
        for (int j = 0;j < c;j++){
            int t;
            scanf("%d",&t);
            courses[t].push_back(temp);
        }
    }
    bool first = true;
    for (int i = 1;i <= m;i++){
        first?first = false:printf("\n");
        printf("%d %d",i,courses[i].size());
        sort(courses[i].begin(),courses[i].end());
        for (int j = 0;j < courses[i].size();j++){
            printf("\n%s",courses[i][j].c_str());
        }
    }
    return 0;
}
