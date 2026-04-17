#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_in_the_circle(pair<ll,ll>a,pair<ll,ll>o,ll r){
    ll dx,dy;
    dx=a.first-o.first;
    dy=a.second-o.second;
    if(dx*dx+dy*dy<r*r)return true;
    return false;
}

int main(){
    ll t;
    cin>>t;
    ll i,j;
    while(t--){
        pair<ll,ll>p1,p2;
        ll ans=0;
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        ll n;
        cin>>n;
        for(i=0;i<n;i++){
            pair<ll,ll>p3;
            ll r;
            cin>>p3.first>>p3.second>>r;
            if(is_in_the_circle(p1,p3,r)^is_in_the_circle(p2,p3,r))ans++;
        }
        cout<<ans<<endl;
    }
}
