#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
//#include<atcoder/all>
//using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = double;
using pld = pair<ld,ld>;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
 
#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif
 
void yes(){
    cout<<"Yes\n";
}
 
void no(){
    cout<<"No\n";
}
 
void preprocess(){
 
}
 
void ask(ll i){
    cout<<"? "<<i<<endl;
}
 
void answer(ll i,ll j){
    cout<<"! "<<i<<endl;
}
 
void solve() {
    int i,j;
    int n;
    ll l;
    ld ans=0;
    bool b=false;
    cin>>n>>l;
    vector<ll> arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(i<n-1){
            if(arr[i]>1)ans=max((ld)(l-arr[i])/(arr[i]-1),ans);
            else ans=max((ld)(l-arr[i]),ans);
        }
        if(i<n-1 && arr[i]!=l)b=true;
    }
    if(!b){
        cout<<"0\n";
        return;
    }
    if(ans<1){
        cout<<fixed<<setprecision(10)<<ans<<'\n';
        return;
    }
    const ld eps=1e-9;
    const ll MAXN=1'048'576;
    int now=n-1;
    ll sum=0;
    bitset<MAXN> bs;
    bs[n]=1;
    while (now >= 0 && sum + arr[now] + n-1-now <= l) {
        sum += arr[now];
        bs[now] = 1;
        now--;
    }
    if(now<0){
        cout<<"1\n";
        return;
    }
//    ld st=1.6, ed=1.6;
    ld st=1, ed=l;
    while(
//            true
            abs((ld)(st-ed)/st)>eps
            ){
        ld mid=(st+ed)/2;
        int cnt=0;
        int f=n-1,t=n-1;
        ld sum1=sum;
        ll sum2=sum;
        for(i=0;i<=now;i++)bs[i]=0;
        for(i=now;i>=0;i--){
            sum1+=arr[i];
            sum2+=arr[i];
//            cout<<sum1<<' '<<sum2<<'\n';
            while(f>i && sum1 + mid*(f-i) > l){
                sum1-=arr[f];
                if(bs[f+1])cnt++;
                f--;
            }
            while(t>i && sum2 + t - i > l){
                sum2-=arr[t];
                if(bs[t+1])cnt--;
                t--;
            }
//            cout<<i<<' '<<f<<' '<<t<<' '<<sum1<<' '<<sum2<<' '<<cnt<<'\n';
            if(arr[i]==1){
                if((l-1<mid&&bs[i+1])||cnt>0){
                    bs[i]=1;
                }
            }
            else{
                if(((ld)(l-arr[i])/(arr[i]-1)<mid&&bs[i+1])||cnt>0){
                    bs[i]=1;
                }
            }
//            cout<<bs[i]<<'\n';
        }
//        for(i=0;i<n;i++)cout<<bs[i]<<' ';cout<<'\n';
        if(bs[0]){
            ed=mid;
        }
        else{
            st=mid;
        }
//        break;
    }
    cout<<fixed<<setprecision(10)<<st<<'\n';
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
