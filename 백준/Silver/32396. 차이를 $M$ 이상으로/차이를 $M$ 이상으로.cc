#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n),dpa(n),dpb(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dpa[0]=0;
    dpb[0]=1;
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])>=m){
            dpa[i]=min(dpa[i-1],dpb[i-1]);
        }
        else dpa[i]=min(dpa[i-1]+1,dpb[i-1]);
        dpb[i]=min(dpa[i-1],dpb[i-1])+1;
    }
    cout<<min(dpa[n-1],dpb[n-1]);
}