#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    vector<bitset<100>>brr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<(1ll<<arr[0])-1<<'\n';
        return;
    }
    ll idx=0;
    for(i=0;i<n-1;i++){
        if(arr[idx]-arr[idx+1]<arr[i]-arr[i+1])idx=i;
    }
    ll dif=arr[idx]-arr[idx+1];
    ll cnt=0;
    for(i=0;i<=dif;i++){
        brr[idx][i]=1;
        cnt++;
    }
    if(dif<=-2){
        cout<<-1<<'\n';
        return;
    }
    for(i=dif+2;cnt<arr[idx];i++){
        brr[idx][i]=1;
        cnt++;
    }
    for(i=idx-1;i>=0;i--){
        brr[i]=brr[i+1].to_ullong()-1;
        if(brr[i].count()!=arr[i]){
            cout<<"-1\n";
            return;
        }
    }
    for(i=idx+1;i<n;i++){
        brr[i]=brr[i-1].to_ullong()+1;
        if(brr[i].count()!=arr[i]){
            cout<<"-1\n";
            return;
        }
    }
    cout<<brr[0].to_ullong()<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)solve();

    return 0;
}