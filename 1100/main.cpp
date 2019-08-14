#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int n;
    map<string, int> mtoe[2];
    map<string, int> test;
    string etom[2][13];
    mtoe[0]["tret"] = 0;
    mtoe[0]["jan"] = mtoe[1]["tam"] = 1;
    mtoe[0]["feb"] = mtoe[1]["hel"] = 2;
    mtoe[0]["mar"] = mtoe[1]["maa"] = 3;
    mtoe[0]["apr"] = mtoe[1]["huh"] = 4;
    mtoe[0]["may"] = mtoe[1]["tou"] = 5;
    mtoe[0]["jun"] = mtoe[1]["kes"] = 6;
    mtoe[0]["jly"] = mtoe[1]["hei"] = 7;
    mtoe[0]["aug"] = mtoe[1]["elo"] = 8;
    mtoe[0]["sep"] = mtoe[1]["syy"] = 9;
    mtoe[0]["oct"] = mtoe[1]["lok"] = 10;
    mtoe[0]["nov"] = mtoe[1]["mer"] = 11;
    mtoe[0]["dec"] = mtoe[1]["jou"] = 12;
    etom[0][0] = "tret";
    etom[1][0] = "";
    etom[0][1] = "jan";
    etom[1][1] = "tam";
    etom[0][2] = "feb";
    etom[1][2] = "hel";
    etom[0][3] = "mar";
    etom[1][3] = "maa";
    etom[0][4] = "apr";
    etom[1][4] = "huh";
    etom[0][5] = "may";
    etom[1][5] = "tou";
    etom[0][6] = "jun";
    etom[1][6] = "kes";
    etom[0][7] = "jly";
    etom[1][7] = "hei";
    etom[0][8] = "aug";
    etom[1][8] = "elo";
    etom[0][9] = "sep";
    etom[1][9] = "syy";
    etom[0][10] = "oct";
    etom[1][10] = "lok";
    etom[0][11] = "nov";
    etom[1][11] = "mer";
    etom[0][12] = "dec";
    etom[1][12] = "jou";
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (isdigit(a[0])){
            int m = stoi(a);
            string ans[2];
            for (int j = 0; j < 2; j++){
                ans[j] = etom[j][m % 13];
                m /= 13;
            }
            for (int j = 1; j >= 0; j--){
               if (j != 1 && ans[1].compare("") != 0)
                    printf(" ");
               cout << ans[j];
            }

            printf("\n");
        }
        else if (getchar() == ' ') {
            string b;
            cin >> b;
            int a1 = mtoe[1][a]*13;
            int a2 = mtoe[0][b];
            int a = a1 + a2;
            printf("%d\n",a);
        }
        else {
            if (mtoe[1].find(a) != mtoe[1].end())
                printf("%d\n",mtoe[1][a] * 13);
            else
                printf("%d\n",mtoe[0][a]);
        }
    }
    return 0;
}
