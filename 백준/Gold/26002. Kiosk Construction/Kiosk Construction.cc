#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (ddebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}
ll n,m;
vector<vector<ll>>arr;
ll dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

ll func(ll a, ll b, ll c, ll d){
    bitset<1800>bs;
    bs[a*(m+2)+b]=1;
    ll nx=a,ny=b,cnt=0;
    while(nx!=c||ny!=d){
        ll nnx=nx+dx[0],nny=ny+dy[0];
        for(ll i=1;i<4;i++){
            ll tx=nx+dx[i],ty=ny+dy[i];
            if(a==2&&b==1&&c==3&&d==3){
                debug<<a*n+m;
            }
            if(abs(arr[nnx][nny]-arr[c][d])>abs(arr[tx][ty]-arr[c][d])){
                nnx=tx,nny=ty;
            }
            else if(abs(arr[nnx][nny]-arr[c][d])==abs(arr[tx][ty]-arr[c][d])
                    &&abs(arr[nnx][nny]-arr[nx][ny])>abs(arr[tx][ty]-arr[nx][ny])){
                nnx=tx,nny=ty;
            }
        }
        if(bs[nnx*(m+2)+nny])return 0;
        bs[nnx*(m+2)+nny]=1;
        nx=nnx,ny=nny;
        cnt++;
    }
    return cnt;
}

ll func2(ll a, ll b){
    ll i,j,cnt=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a==i&&b==j)continue;
            else{
                ll tmp=func(a,b,i,j);
                if(!tmp){
                    return 0;
                }
                else{
                    cnt=max(cnt,tmp);
                }
            }
        }
    }
    return cnt;
}

void solve(ll testcase) {
    ll i,j,k,ai,aj;
    cin>>n>>m;
    arr.resize(n+2,vector<ll>(m+2,INT_MAX));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    ll cnt=INT_MAX;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            ll tmp=func2(i,j);
            if(cnt>tmp&&tmp){
                cnt=tmp;
                ai=i,aj=j;
            }
        }
    }
    if(cnt==INT_MAX){
        cout<<"impossible\n";
    }
    else cout<<arr[ai][aj]<<' '<<cnt;
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}