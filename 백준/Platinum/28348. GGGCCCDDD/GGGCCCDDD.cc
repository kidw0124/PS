#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

constexpr ll mod = 1e9+7;
const ll MAXN=1001;
vector<vector<ll>>gcds(MAXN,vector<ll>(MAXN));
ll gcd(ll a, ll b){
    if(a==0||b==0)return a+b;
    else if(gcds[a][b])return gcds[a][b];
    else if(a%b==0)return gcds[a][b]=b;
    else return gcds[a][b]=gcd(b,a%b);
}

void preprocess(){
    ll i,j, k;
    for(i=1;i<MAXN;i++){
        for(j=1;j<MAXN;j++){
            gcd(i,j);
        }
    }
}

void solve(){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    auto func=[&](ll m,auto&&f){
        if(m==1){
            vector<ll>arr(n+1,1);
            return arr;
        }
        else{
            auto bb=f(m>>1,f);
            vector<ll>ret(n+1);
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    ret[gcds[i][j]]+=bb[i]*bb[j]%mod;
                    ret[gcds[i][j]]%=mod;
                }
            }
            if(m&1){
                bb=ret;
                ret.assign(n+1,0);
                for(ll i=1;i<=n;i++){
                    for(ll j=1;j<=n;j++){
                        ret[gcds[i][j]]+=bb[i];
                        ret[gcds[i][j]]%=mod;
                    }
                }
            }
            return ret;
        }
    };
    auto arr=func(m,func);
    ll ans=0;
    for(i=1;i<=n;i++){
        ans+=arr[i]*i%mod;
        ans%=mod;
    }
    cout<<ans<<'\n';

}
//void solve2(){
//    ll a,b,c,d,e,f,g,h;
//    a=b=c=d=e=f=g=h=0;
//    ll n,m;
//    ll ans=0;
//    cin>>n>>m;
//    for(a=1;a<=n;a++){
//        if(m<2){
//            ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//            ans%=mod;
//        }
//        else{
//            for(b=1;b<=n;b++){
//                if(m<3){
//                    ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                    ans%=mod;
//                }
//                else{
//                    for(c=1;c<=n;c++){
//                        if(m<4){
//                            ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                            ans%=mod;
//                        }
//                        else{
//                            for(d=1;d<=n;d++){
//                                if(m<5){
//                                    ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                                    ans%=mod;
//                                }
//                                else{
//                                    for(e=1;e<=n;e++){
//                                        if(m<6){
//                                            ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                                            ans%=mod;
//                                        }
//                                        else{
//                                            for(f=1;f<=n;f++){
//                                                if(m<7){
//                                                    ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                                                    ans%=mod;
//                                                }
//                                                else{
//                                                    for(g=1;g<=n;g++){
//                                                        if(m<8){
//                                                            ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                                                            ans%=mod;
//                                                        }
//                                                        else{
//                                                            for(h=1;h<=n;h++){
//                                                                if(m<9){
//                                                                    ans+=gcd(a,gcd(b,gcd(c,gcd(d,gcd(e,gcd(f,gcd(g,h)))))));
//                                                                    ans%=mod;
//                                                                }
//                                                                else{
//
//                                                                }
//                                                            }
//                                                        }
//                                                    }
//                                                }
//                                            }
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    cout<<ans<<'\n';
//
//}


int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    preprocess();
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++)solve();
//    cout<<"=====\n";
//    for(ll i=0;i<t;i++)solve2();
}