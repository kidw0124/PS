#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j;
    ll n,rs,sxs=0,sys=0;
    __float128 sx=0,sy=0;
    cin>>n>>rs;
    vector<pair<__float128,__float128>> points(n);
    for(i=0;i<n;i++){
        ll tx,ty;
        cin>>tx>>ty;
        sxs+=abs(tx);
        sys+=abs(ty);
        points[i].first=sqrt((long double)abs(tx))*(tx>0?1:-1);
        points[i].second=sqrt((long double)abs(ty))*(ty>0?1:-1);
        sx+=points[i].first;
        sy+=points[i].second;
    }
    cout<<fixed<<setprecision(10)<<((long double)(4*rs-8*n*rs/((__float128)(n-1)*3)+8*(sx*sx+sy*sy)/(n*(n-1)*3)))<<'\n';

}