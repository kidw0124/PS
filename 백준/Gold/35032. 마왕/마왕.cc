#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void preprocess(){
    ll i,j,k;
}

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll,ll>>arr(n);
    i=0;
    for(auto&[x,y,r,p]:arr){
        cin>>x>>y>>r;p=++i;
    }
    ranges::sort(arr.begin(), arr.end(),[](auto&x,auto&y){
        return get<2>(x)>get<2>(y);
    });
    auto chk2=[](const ll x1, const ll y1, const ll r1,const ll x2, const ll y2){
        if((x1-r1<=x2&&x2<=x1+r1)&&(y1-r1<=y2&&y2<=y1+r1))return true;
        return false;
    };
    auto chk=[&chk2](const auto&f,const auto&s)->bool{
        const auto&[x1,y1,r1,n1]=f;
        const auto&[x2,y2,r2,n2]=s;
        return chk2(x1,y1,r1,x2-r2,y2-r2)
                ||chk2(x1,y1,r1,x2-r2,y2+r2)
                ||chk2(x1,y1,r1,x2+r2,y2+r2)
                ||chk2(x1,y1,r1,x2+r2,y2-r2)
                ||chk2(x2,y2,r2,x1-r1,y1-r1)
                ||chk2(x2,y2,r2,x1-r1,y1+r1)
                ||chk2(x2,y2,r2,x1+r1,y1+r1)
                ||chk2(x2,y2,r2,x1+r1,y1-r1);
    };
    vector<tuple<ll,ll,ll,ll>>ans;
    for(auto&x:arr){
        bool r=0;
        for(auto&y:ans){
            if(chk(x,y)){
                r=1;
                break;
            }
        }
        if(!r)ans.push_back(x);
    }
    cout<<ans.size()<<"\n";
    for(auto&[x,y,r,l]:ans)cout<<l<<"\n";


}

int main(){
#ifndef kidw0124
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();

}