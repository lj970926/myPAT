#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int r[1005] = {0}, minr[500], maxr[500];
bool h[505] = {false};
int main()
{
    fill(minr, minr + 500, 0x3fffffff);
    fill(maxr, maxr + 500, 0);
    int k;
    scanf("%d", &k);
    string s;
    string ans;
    cin >> s;
    r[0] = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i - 1])
            r[i] = r[i - 1] + 1;
        else
            r[i] = 1;
    }
    r[s.size()] = 1;
    int i = 0;
    while (i < s.size()){
        if (r[i + 1] == 1){
            char c = s[i];
            int r1 = r[i] % k;
            if (minr[c] > r1) minr[c] = r1;
            if (maxr[c] < r1) maxr[c] = r1;
        }
        i++;
    }
    for (int i = 0; i < s.size(); i++){
        if (minr[s[i]] == maxr[s[i]]){
            int r = minr[s[i]];
            if (r % k == 0 && !h[s[i]]){
                printf("%c", s[i]);
                h[s[i]] = true;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < s.size(); i++){
        printf("%c", s[i]);
        if (h[s[i]])
            i += (k - 1);
    }
    return 0;
}
