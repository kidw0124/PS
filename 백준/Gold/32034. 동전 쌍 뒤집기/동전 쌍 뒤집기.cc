#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void solve(){
    int i,j,k;
    int n;
    cin>>n;
    string str;
    cin>>str;
    stack<int>stk;
    ll ans=0;
    for(i=0;i<n;i++){
        if(str[i]=='T'){
            if(stk.empty() || (stk.top()-i)%2==0){
                stk.push(i);
            }
            else{
                ans+=i-stk.top();
                stk.pop();
            }
        }
    }
    if(stk.size())cout<<"-1\n";
    else cout<<ans<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}