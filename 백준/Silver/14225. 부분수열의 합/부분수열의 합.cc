#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll i,j;
    ll n,m;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>bs(2'000'001);
    for(auto&k:arr)cin>>k;
    ll cnt=0;
    for(i=1;i<(1<<n);i++){
        ll sum=0;
        for(j=0;j<n;j++){
            if(i>>j&1){
                sum+=arr[j];
            }
        }
        bs[sum]=1;
    }
    for(i=1;i<=(1<<n);i++)if(!bs[i]){cout<<i;return 0;}
}