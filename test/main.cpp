#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> st;
    st.insert(1);
    auto itr = st.end();
    itr--;
    return 0;
}
