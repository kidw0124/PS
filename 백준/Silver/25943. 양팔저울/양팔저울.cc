#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    ll a=0,b=0;
    for(i=0;i<n;i++){
        if(a<=b)a+=arr[i];
        else b+=arr[i];
    }
    ll c=abs(a-b);
    ll ans=0;
    vector<ll>choo({100,50,20,10,5,2,1});
    while(c){
        for(i=0;i<7;i++){
            ans+=c/choo[i];
            c%=choo[i];
        }
    }
    cout<<ans;
}