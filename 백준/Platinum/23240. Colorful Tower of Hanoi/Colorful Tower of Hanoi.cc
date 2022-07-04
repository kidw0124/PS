#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    ll i,j;
    cin.tie(0);
    cin>>n;
    vector<pair<char,ll>>arr(n);
    for(i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    ll ans=0;
    bool c=0;
    for(i=n-1;i>=0;i--){
        ll x=arr[i].second;
        ll t=1;
        for(j=i-1;j>=0;j--){
            x+=arr[j].second*t;
            t<<=1;
        }
        if(!c){
            if(arr[i].first=='B'&&arr[i].second!=1&&i){
                ans+=2*x;
                c=0;
            }
            else if(arr[i].first=='B'&&i==0){
                ans+=2*x-1;
            }
            else{
                ans+=x;
                c=1;
            }
        }
        else{
            if(arr[i].first=='R'&&arr[i].second!=1&&i){
                ans+=2*x;
                c=0;
            }
            else if(arr[i].first=='R'&&i==0){
                ans+=2*x-1;
            }
            else{
                ans+=x;
                c=1;
            }
        }
    }
    cout<<ans;
}
