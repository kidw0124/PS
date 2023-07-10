#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, i;
    cin >> n;
    vector<ll>arr(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    vector<bool>vis(n+1);
    stack<ll>stk({1});
    vis[1]=1;
    while(!stk.empty()){
        ll now=stk.top();
        stk.pop();
        if(arr[now]==n){
            cout<<ans+1<<'\n';
            return;
        }
        if(!vis[arr[now]]){
            stk.push(arr[now]);
            vis[arr[now]]=1;
            ans++;
        }
    }
    cout<<0<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}