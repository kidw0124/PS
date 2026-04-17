//#include<bits/stdc++.h>
//#pragma warning(disable:4996)
//#pragma comment(linker, "/STACK:336777216")
//using namespace std;
//typedef long long ll;
//typedef long long LL;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef pair<ll, ll> pll;
//typedef vector<ll> vl;
//#define pb(x) push_back(x)
//#define all(x) (x).begin(), (x).end()
//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
//ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
//ll n,k;
//vector<vector<pll>>grp;
//vector<vector<ll>>anc;
//vector<vector<ll>>lo;
//vector<vector<ll>>hi;
//vector<ll>depth;
//
//pll lca(ll x, ll y){
//    ll mi=INT_MAX,ma=INT_MIN;
//    if(depth[x]>depth[y])swap(x,y);
//    if(depth[x]!=depth[y]){
//        ll k=depth[y]-depth[x];
//        ll c=0;
//        while(k){
//            if(k&1){
//                mi=min(mi,lo[y][c]);
//                ma=max(ma,hi[y][c]);
//                y=anc[y][c];
//            }
//            c++;
//            k>>=1;
//        }
//    }
//    if(x==y) return{mi,ma};
//    for(ll i=anc[x].size()-1;i>=0;i--){
//        if(anc[x][i]!=anc[y][i]){
//            mi=min(min(mi,lo[x][i]),lo[y][i]);
//            ma=max(max(ma,hi[x][i]),hi[y][i]);
//            x=anc[x][i];
//            y=anc[y][i];
//        }
//    }
//    mi=min(min(mi,lo[x][0]),lo[y][0]);
//    ma=max(max(ma,hi[x][0]),hi[y][0]);
//    return{mi,ma};
//}
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    ll i,j;
//    cin>>n;
//    grp.resize(n+1);
//    anc.resize(n+1);
//    lo.resize(n+1);
//    hi.resize(n+1);
//    dist.resize(n+1);
//    depth.resize(n+1,-1);
//    for(i=0;i<n-1;i++){
//        ll a,b,c;
//        cin>>a>>b>>c;
//        grp[a].push_back({b,c});
//        grp[b].push_back({a,c});
//    }
//    queue<ll> que;
//    que.push(1);
//    anc[1].push_back(0);
//    lo[1].push_back(INT_MAX);
//    hi[1].push_back(INT_MIN);
//    depth[1]=1;
//    while(!que.empty()){
//        ll x=que.front();
//        que.pop();
//        for(auto i:grp[x]){
//            if(i.first==anc[x][0])continue;
//            else{
//                que.push(i.first);
//                anc[i.first].push_back(x);
//                depth[i.first]=depth[x]+1;
//                lo[i.first].push_back(i.second);
//                hi[i.first].push_back(i.second);
//                for(ll j=1, k=1;k<depth[i.first];k<<=1,j++){
//                    anc[i.first].push_back(anc[anc[i.first][j-1]][j-1]);
//                    lo[i.first].push_back(min(lo[i.first][j-1],lo[anc[i.first][j-1]][j-1]));
//                    hi[i.first].push_back(max(hi[i.first][j-1],hi[anc[i.first][j-1]][j-1]));
//                }
//            }
//        }
//    }
//    ll m;
//    cin>>m;
////    for(i=1;i<=n;i++){
////        cout<<i<<' '<<depth[i]<<' '<<anc[i].size()<<'\n';
////        for(j=0;j<anc[i].size();j++){
////            cout<<anc[i][j]<<' ';
////        }
////        cout<<'\n';
////        for(j=0;j<lo[i].size();j++){
////            cout<<lo[i][j]<<' ';
////        }
////        cout<<'\n';
////        for(j=0;j<hi[i].size();j++){
////            cout<<hi[i][j]<<' ';
////        }
////        cout<<'\n';
////        cout<<'\n';
////    }
//    for(i=0;i<m;i++){
//        ll a,b;
//        cin>>a>>b;
//        pll c=lca(a,b);
//        cout<<c.first<<' '<<c.second<<'\n';
//    }
//
//    return 0;
//}
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,k;
vector<vector<pll>>arr;
vector<ll>dpt;
vector<vector<ll>>anc;
vector<vector<pll>>mima;
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll i,j;
    cin>>n;;
    arr.resize(n+1);
    dpt.resize(n+1);
    anc.resize(n+1,vector<ll>(20));
    mima.resize(n+1,vector<pll>(20,{(ll)INT_MAX,(ll)INT_MIN}));
    for(i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    dpt[1]=1;
    queue<ll>que;
    que.push(1);
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto kk:arr[now]){
            ll k=kk.first;
            ll l=kk.second;
            if(dpt[k])continue;
            dpt[k]=dpt[now]+1;
            anc[k][0]=now;
            mima[k][0]={l,l};
            que.push(k);
        }
    }
    for(i=1;i<20;i++){
        for(j=1;j<=n;j++){
            anc[j][i]=anc[anc[j][i-1]][i-1];
            mima[j][i]={min(mima[anc[j][i-1]][i-1].first,mima[j][i-1].first),max(mima[anc[j][i-1]][i-1].second,mima[j][i-1].second)};
        }
    }
    cin>>k;
    for(i=0;i<k;i++){
        ll a,b,p=INT_MAX,q=INT_MIN;
        cin>>a>>b;
        if(dpt[a]>dpt[b])swap(a,b);
        ll dd=dpt[b]-dpt[a];
        for(j=0;dd;j++){
            if(dd&1){
                p=min(p,mima[b][j].first);
                q=max(q,mima[b][j].second);
                b=anc[b][j];
            }
            dd>>=1;
        }
        if(a!=b){
            while(anc[a][0]!=anc[b][0]){
                for(j=0;anc[a][j+1]!=anc[b][j+1];j++);
                p=min({p,mima[a][j].first,mima[b][j].first});
                q=max({q,mima[a][j].second,mima[b][j].second});
                a=anc[a][j],b=anc[b][j];
            }
            p=min({p,mima[a][0].first,mima[b][0].first});
            q=max({q,mima[a][0].second,mima[b][0].second});
        }
        cout<<p<<' '<<q<<'\n';
    }
    return 0;
}
