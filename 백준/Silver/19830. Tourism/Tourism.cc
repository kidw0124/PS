#include <bits/stdc++.h>
using namespace std;

void solve() {
    int i,j;
    string str;
    cin>>str;
    int a=str.find('0'),b=str.find_last_of('0');
    if(str.find_last_of('1')-str.find('1')>b-a){
        a=str.find('1');
        b=str.find_last_of('1');
    }
    a++,b++;
    cout<<a+1<<' '<<b<<' '<<a<<' '<<b-1<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}