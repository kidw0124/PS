#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll i,j;
    ll n;
    vector<ll>arr(10000+1);
    arr[0]=1;
    for(i=1;i<=10000;i++){
        for(j=0;j<i;j++){
            arr[i]+=arr[j]*arr[i-j-1]%mod;
            arr[i]%=mod;
        }
    }
    cin>>n;
    cout<<arr[n];
}
