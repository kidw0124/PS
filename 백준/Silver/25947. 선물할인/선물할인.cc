#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b,i,j,st,ed,md,sum,res;
    cin>>n>>b>>a;
    st=0;
    ed=n;
    vector<ll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    while(st<ed){
        md=(st+ed+1)/2;
        sum=0;
        if(md<=a){
            for(i=0;i<md;i++)sum+=(arr[i]/2);
        }
        else{
            for(i=md-1;i>=md-a;i--)sum+=(arr[i]/2);
            for(i=md-a-1;i>=0;i--)sum+=arr[i];
        }
        if(sum<=b)st=md;
        else ed=md-1;
    }
    md=(st+ed)/2;
    if(arr[0]>b)md=0;
    cout<<md;
    return 0;
}