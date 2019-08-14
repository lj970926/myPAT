#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu{
    string name, id;
    int grade;
};
vector<Stu> stu;

bool cmp(Stu &a, Stu &b){
    return a.grade > b.grade;
}

int main()
{
    int n, lb, rb;
    cin >> n;
    for (int i = 0; i < n; i++){
        Stu s;

        cin >> s.name >> s.id >> s.grade;
        stu.push_back(s);
    }
    scanf("%d %d", &lb, &rb);
    sort(stu.begin(), stu.end(), cmp);
    int fr = 0, re = stu.size() - 1;
    while (fr < stu.size() && stu[fr].grade > rb) fr++;
    while (re >= 0 && stu[re].grade < lb) re--;
    if (fr > re)
        printf("NONE");
    else
        for (int i = fr; i <= re; i++){
            printf("%s %s\n", stu[i].name.c_str(), stu[i].id.c_str());
        }
    return 0;
}
