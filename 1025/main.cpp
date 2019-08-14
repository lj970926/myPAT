#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct testee{
    string id;
    int f_rank;
    int loc_num;
    int loc_rank;
    int grade;
};

bool cmp(const testee &a,const testee &b){
    return (a.grade > b.grade||(a.grade == b.grade&&a.id.compare(b.id) < 0));
}

int main()
{
    int num_pos,num_stu;
    vector<testee> f_testees;
    cin >> num_pos;
    for (int i = 0;i < num_pos;i++){
        vector<testee> l_testees;
        cin >> num_stu;
        for (int j = 0;j < num_stu;j++){
            testee temp;
            cin >> temp.id >> temp.grade;
            temp.loc_num = i+1;
            l_testees.push_back(temp);
        }
        sort(l_testees.begin(),l_testees.end(),cmp);
        l_testees[0].loc_rank = 1;
        for (int k = 1;k < l_testees.size();k++)
            l_testees[k-1].grade == l_testees[k].grade ? l_testees[k].loc_rank = l_testees[k-1].loc_rank
                                                    :l_testees[k].loc_rank = k+1;
        for (int m = 0;m < l_testees.size();m++) f_testees.push_back(l_testees[m]);
    }
    sort(f_testees.begin(),f_testees.end(),cmp);
    f_testees[0].f_rank = 1;
    for (int k = 1;k < f_testees.size();k++)
        f_testees[k-1].grade == f_testees[k].grade ? f_testees[k].f_rank = f_testees[k-1].f_rank
                                                    :f_testees[k].f_rank = k+1;
    bool first = true;
    cout << f_testees.size() << endl;
    for (int i = 0;i < f_testees.size();i++){
        first ?  first = false:printf("\n");
        printf("%s %d %d %d",f_testees[i].id.c_str(),f_testees[i].f_rank,f_testees[i].loc_num,f_testees[i].loc_rank);
    }

    return 0;
}
