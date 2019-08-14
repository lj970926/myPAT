#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Student{
    int id;
    string name;
    int grade;

};

bool cmp1(const Student &a, const Student &b){
    return a.id < b.id;
}

bool cmp2(const Student &a, const Student &b){
    return(a.name.compare(b.name) < 0||(a.name.compare(b.name)==0&&a.id < b.id));
}
bool cmp3(const Student &a, const Student &b){
    return (a.grade < b.grade||(a.grade == b.grade&&a.id < b.id));
}

int main()
{
    int n,c;
    vector<Student> students;
    cin >> n >> c;
    for (int i = 0; i < n; i++){
        Student temp;
        cin >>temp.id >> temp.name >> temp.grade;
        students.push_back(temp);
    }
    switch(c){
        case 1: sort(students.begin(),students.end(),cmp1);break;
        case 2: sort(students.begin(),students.end(),cmp2);break;
        case 3: sort(students.begin(),students.end(),cmp3);break;
    }
    bool first = true;
    for (int i = 0;i < students.size();i++){
            first ? first = false:printf("\n");
        printf("%06d %s %d",students[i].id,students[i].name.c_str(),students[i].grade);
    }

    return 0;
}
