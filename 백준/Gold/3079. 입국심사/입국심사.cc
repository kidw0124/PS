#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    vector<ll> t(n);
    int i,j;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    sort(t.begin(),t.end());
    ll lef=0,rig=t[n-1]*m;
    while(lef<rig){
        ll mid=(lef+rig)/2,sum=0;
        for(i=0;i<n;i++){
            sum+=mid/t[i];
        }
        if(sum<m) lef=mid+1;
        else if(sum>=m) rig=mid;
    }
    cout<<lef;
}
