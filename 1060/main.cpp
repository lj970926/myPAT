#include <iostream>
#include <cstring>
char a[105], b[105], na[105], nb[105];
using namespace std;
int sig;

int main()
{
    scanf("%d %s %s", &sig, a, b);
    int lena = strlen(a), lenb = strlen(b);
    int pa = 0, pb = 0;
    while (pa < lena && a[pa] != '.') pa++;
    while (pb < lenb && b[pb] != '.') pb++;
    int sa = 0, sb = 0;
    while (a[sa] == '0'|| a[sa] == '.') sa++;
    while (b[sb] == '0'|| b[sb] == '.') sb++;
    int ka = pa - sa, kb = pb - sb;
    if (ka < 0)
        ka++;
    if (kb < 0)
        kb++;
    if (sa == lena) ka = 0;
    if (sb == lenb) kb = 0;
    int ia = 0;
    while (ia < sig){
        if(sa < lena && a[sa] != '.')
            na[ia++] = a[sa++];
        else if (sa >= lena)
            na[ia++] = '0';
        else sa++;

    }
    int ib = 0;
    while(ib < sig){
        if (sb < lenb && b[sb] != '.')
            nb[ib++] = b[sb++];
        else if (sb >= lenb)
            nb[ib++] = '0';
        else sb++;
    }
    if (strcmp(na, nb) == 0 && ka == kb){
        printf("YES 0.%s*10^%d", na, ka);
    }
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d", na, ka, nb, kb);
}
