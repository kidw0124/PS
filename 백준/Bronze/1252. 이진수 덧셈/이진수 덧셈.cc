#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 998244353;
void solve() {
    ll i, j, k;
    string a,b;
    cin>>a>>b;
    a=a.substr(max(0,(int)((a.find('1')+a.size())%a.size())));
    b=b.substr(max(0,(int)((b.find('1')+b.size())%b.size())));
    while(a.size()<b.size()){
        a="0"+a;
    }
    while(a.size()>b.size()){
        b="0"+b;
    }
    int x=0;
    stack<char>stk;
    for(i=a.size()-1;i>=0;i--){
        stk.push((a[i]-'0')^(b[i]-'0')^x);
        x=(((a[i]-'0')^(b[i]-'0'))&x)|((a[i]-'0')&(b[i]-'0'));
    }
    if(x)stk.push(x);
    while(!stk.empty())cout<<(stk.top()==1),stk.pop();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();

    return 0;
}