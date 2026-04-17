#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n=3;
    vector<ll>arr(3);
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(i=3;i<=arr[1];i++){
        if(arr[0]>=i){
            ans+=((i-1)/2)*6*8;
        }
        else if(arr[0]>=i/2){
            ans+=(arr[0]-i/2)*2*8;
        }
        else break;
    }
    cout<<ans;
}
