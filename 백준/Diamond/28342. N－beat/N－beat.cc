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

ll ipow(ll a, ll b){
    if(b){
        ll now= ipow(a,b>>1);
        return now*now%mod*(b&1?a:1)%mod;
    }
    else return 1;
}

ll modinv(ll a){
    return ipow(a,mod-2);
}

constexpr ll MAXN = 1e6;

vector<ll>facto(MAXN+1),invfacto(MAXN+1);

ll ncr(ll n, ll r){
    if(n<r)return 0;
    else return facto[n]*invfacto[r]%mod*invfacto[n-r]%mod;
}

void preprocess(){
    ll i,j;
    facto[0]=1;
    for(i=1;i<=MAXN;i++)facto[i]=facto[i-1]*i%mod;
    invfacto[MAXN]= modinv(facto[MAXN]);
    for(i=MAXN-1;i>=0;i--)invfacto[i]=(i+1)*invfacto[i+1]%mod;
}

vector<vector<ll>>operator*(const vector<vector<ll>>&a, const vector<vector<ll>>&b){
    vector<vector<ll>>ret(a.size(),vector<ll>(b[0].size()));
    ll i,j,k;
    for(i=0;i<a.size();i++){
        for(j=0;j<a[0].size();j++){
            for(k=0;k<b[0].size();k++){
                ret[i][k]+=a[i][j]*b[j][k]%mod;
                ret[i][k]%=mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>>operator^(const vector<vector<ll>>&a, const ll b){
    ll n=a.size();
    ll i;
    if(b){
        auto now= a^(b>>1);
        now=now*now;
        if(b&1)now=now*a;
        return now;
    }
    else{
        vector<vector<ll>>ret(n,vector<ll>(n));
        for(i=0;i<n;i++)ret[i][i]=1;
        return ret;
    }
}

void solve(ll tc){
    ll i,j;
    ll x,y,b,_1,_2,_3;
    cin>>x>>y>>b>>_1>>_2>>_3;
    if(b==1){
        ll ans=0;
        for(i=0;i<=_1;i++){
            ans+=ncr(x*y,i);
            ans%=mod;
        }
        cout<<ans<<'\n';
        return;
    }
    vector<pll>_2s;
    map<pll,ll>rev2;
    for(i=0;i<=_1;i++){
        for(j=0;j<=_1;j++){
            if(i+j<=_2){
                rev2[{i,j}]=_2s.size();
                _2s.push_back({i,j});
            }
        }
    }
    ll n=_2s.size();
    vector<vector<ll>>mat(n,vector<ll>(n));
    for(i=0;i<n;i++){
        auto [p,q]=_2s[i];
        for(j=0;j<n;j++){
            auto [r,s]=_2s[j];
            if(r==q && p+q+s<=_3){
                mat[j][i]=ncr(x*y,s);
            }
        }
    }
//    for(i=0;i<n;i++){
//        cout<<"i : "<<i<<" , "<<_2s[i].first<<" "<<_2s[i].second<<"\n";
//    }
//    for(i=0;i<n;i++){
//        for(j=0;j<n;j++){
//            cout<<mat[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
    mat=mat^(b-2);
//    for(i=0;i<n;i++){
//        for(j=0;j<n;j++){
//            cout<<mat[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
    vector<vector<ll>>vec(n,vector<ll>(1));
    for(i=0;i<n;i++){
        auto [p,q]=_2s[i];
        vec[i][0]=ncr(x*y,p)*ncr(x*y,q)%mod;
    }
    mat=mat*vec;
    ll ans=0;
//    for(i=0;i<n;i++){
//        for(j=0;j<1;j++){
//            cout<<mat[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
    for(i=0;i<n;i++){
        ans+=mat[i][0];
        ans%=mod;
    }
    cout<<ans<<'\n';

}

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
    for(ll i=0;i<t;i++)solve(i+1);
}