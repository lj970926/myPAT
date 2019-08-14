#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    char map[] = "0123456789ABC";
    vector<int> result;
    int r,g,b,pos;
    scanf("%d %d %d",&r,&g,&b);
    pos = 0;
    while(b != 0 || pos < 2){
        result.push_back(b%13);
        b/=13;
        pos++;
    }
    pos = 0;
    while (g != 0|| pos < 2){
        result.push_back(g%13);
        g/=13;
        pos++;
    }
    pos = 0;
    while (r != 0|| pos < 2){
        result.push_back(r%13);
        r/=13;
        pos++;
    }
    printf("#");
    for (int i = result.size()-1;i >= 0;i--)
        printf("%c",map[result[i]]);
    return 0;
}
