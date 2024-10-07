#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string str;
    cin>>str;
    int cnt=0;
    for(int i=0;i<str.size();i++){
        cout<<str[i];
        cnt++;
        if(cnt%10==0)cout<<"\n";
    }
}
