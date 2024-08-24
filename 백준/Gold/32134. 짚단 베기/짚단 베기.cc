#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void preprocess() {

}

void solve() {
    ll i,j;
    ll n;
    ll h,s;
    cin>>n>>h>>s;
    vector<ll>f(n);
    for(i=0;i<n;i++)cin>>f[i];
    ll sf=0,sif=0;
    for(i=0;i<n;i++){
        sf+=f[i];
        sif+=f[i]*(i+1);
    }
    ld ans=1e18;
    ld a=0,eps=1e-11;
    auto check=[&](ld a)->ld{
        ld b=(2*s/(ld)n)-a;
        if(b>=0 && b<=h){
            ld t=(a-(b-a)/(2*n))*sf+(b-a)/n*sif;
            return t;
        }
        else return 1e18;
    };
    ld st=max((ld)0,2*s/(ld)n-h),en=min((ld)h,2*s/(ld)n)+eps;
    while(en-st>eps){
        ld mid=(st+en)/2;
        if(check(mid)<check(mid+eps))en=mid;
        else st=mid;
    }
    cout<<fixed<<setprecision(12)<<check(st)<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
