#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string fname,mname;
    int gradem = 101,gradef = -1;
    for (int i = 0;i < n;i++){
        string name,id;char sex;int grade;
        cin >> name >> sex >> id >> grade;
        if (sex == 'M'){
            if (grade < gradem){
                gradem = grade;
                mname = name + " " + id;
            }
        }
        else{
            if (grade > gradef){
                gradef = grade;
                fname = name + " " + id;
            }
        }
    }
    if (gradef == -1)
        cout << "Absent" << endl;
    else
        cout << fname << endl;
    if (gradem == 101)
        cout << "Absent" << endl;
    else
        cout << mname << endl;
    if (gradef == -1 || gradem == 101)
        cout << "NA";
    else
        cout << gradef - gradem;
    return 0;
}

/*
    note: ���Ա߶����Ѱ����ֵ������洢
    name �� id �ɺ�Ϊһ��string �洢
*/
