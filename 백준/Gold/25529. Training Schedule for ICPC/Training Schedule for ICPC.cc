#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void preprocess(){
}

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    auto func=[&](ll g){
        ll t=m/(g+1),r=m%(g+1);
        return (n-g+1)*(n-g+1)+g-1
                -t*t*(g+1-r)-(t+1)*(t+1)*r;
    };
    if(n+m==0)exit(0);
    if(n==0){
        cout<<-m*m<<'\n';
    }
    else if(m==0){
        cout<<n*n<<'\n';
    }
    else if(m==1){
        cout<<n*n-1<<'\n';
    }
    else{
        ll s=1,e=min(n,m-1);
        while(s<e){
            ll mid1=(s+s+e)/3;
            ll mid2=mid1+1;
            ll f1=func(mid1),f2=func(mid2);
            if(f1>=f2){
                e=mid2-1;
            }
            else{
                s=mid1+1;
            }
        }
        cout<<func(s)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(true)solve();
    return 0;
}