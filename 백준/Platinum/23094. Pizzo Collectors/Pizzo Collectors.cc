#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if constexpr(ddebug) cout<<"[DEBUG] "

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j;
}

ll mod = 167772161;
ll n, m,M;
ll p;
string str;
vector<ll>cost('Z'+1,0);

//ll calc(ll)

ll func(ll st, ll per){
   if(per==n){
        if(str[st]=='?')return M;
        else return cost[str[st]];
    }
    ll ret=0;
    ll i,j,tst=st;
    char c=str[st];
    while(c=='?'&&tst<n){
        c=str[tst];
        tst+=per;
    }
    for(i=st;i<n;i+=per){
        if(c!=str[i]&&str[i]!='?'&&c!='?')break;
    }
    if(i>=n){
        ll rem = n/per;
        ll alpha = 1+(ll)(log((ld)rem+1e-6)/log((ld)p));
        ret=(c=='?'?M:cost[c])*rem*alpha;
    }
    ll tmp=0;
    for(i=0;i<p;i++){
        tmp+=func(st+i*per,per*p);
    }
    ret=max(tmp,ret);
    debug<<st<<' '<<per<<' '<<ret<<'\n';
    return ret;
}

void solve(ll testcase){
    ll i, j, k;
    cin>>n;
    for(p=2;p<=n;p++){
        if(n%p==0)break;
    }
    cin>>str;
    cin>>m;
    for(i=0;i<m;i++){
        char c;
        cin>>c>>j;
        cost[c]=j;
        M=max(M,j);
    }
    cout<<func(0,1);
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}