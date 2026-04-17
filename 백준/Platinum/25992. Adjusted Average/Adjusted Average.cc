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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using ordered_multiset=tree<ld, null_type, less_equal<>, rb_tree_tag,tree_order_statistics_node_update>;
void m_erase(ordered_multiset &OS, ld val){
    ll index = OS.order_of_key(val);
    ordered_multiset::iterator it = OS.find_by_order(index);
    if(abs(*it -val)<1e-9) OS.erase(it);
}
void preprocess() {
    ll i, j, k;
}

ll n,r;
ld p;
ld sum;
vector<ld>arr;

ld func1(ld s){
    ld q=LLONG_MAX;
    for(ll i=0;i<n;i++){
        if(abs(s-q)>abs(s-arr[i]))q=arr[i];
    }
    return q;
}

ld func2(ld s){
    ld q=LLONG_MAX;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++) {
            if (abs(s - q) > abs(s - arr[i] - arr[j]))q = arr[i] + arr[j];
        }
    }
    return q;
}

ld func3(ld s){
    ld q=LLONG_MAX;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++) {
            ld tmp=arr[i]+arr[j];
            ll idx= lower_bound(arr.begin()+j+1,arr.end(),s-tmp)-arr.begin();
            if(idx>j+1){
                ld t2=arr[idx-1];
                if (abs(s - q) > abs(s - tmp-arr[idx-1]))q =tmp+t2;
            }
            if(idx<n){
                if (abs(s - q) > abs(s - tmp-arr[idx]))q = arr[i] + arr[j]+arr[idx];
            }
            if(idx+1<n){
                if (abs(s - q) > abs(s - tmp-arr[idx+1]))q = arr[i] + arr[j]+arr[idx+1];
            }
        }
    }
    return q;
}

ld func4(ld s){
    ordered_multiset OS;
    ll i,j,k;
    ld q=LLONG_MAX;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            OS.insert(arr[i]+arr[j]);
        }
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n;j++){
            m_erase(OS,arr[i]+arr[j]);
        }
        for(j=0;j<i;j++){
            ld tmp=arr[i]+arr[j];
            ll idx=OS.order_of_key(s-(arr[i]+arr[j]));
//            debugv(tmp)
            if(idx){
                ld t2=*OS.find_by_order(idx-1);
//                debugv(t2)
                if (abs(s - q) > abs(s - tmp-t2))q =tmp+t2;
            }
            if(idx<OS.size()){
                ld t2=*OS.find_by_order(idx);
//                debugv(t2)
                if (abs(s - q) > abs(s - tmp-t2))q =tmp+t2;
            }
            if(idx+1<OS.size()){
                ld t2=*OS.find_by_order(idx+1);
//                debugv(t2)
                if (abs(s - q) > abs(s - tmp-t2))q =tmp+t2;
            }
        }
    }
    return q;
}


void solve(ll testcase) {
    ll i, j, k;
    cin >> n>>r>>p;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(all(arr));
    cout<<fixed<<setprecision(10);
    ld ans=sum/n;
    if(r>=1){
        ld o = func1(sum-p*(n-1));
        ld nea=(sum-o)/(n-1);
        debugv(abs(p-nea));
        if(abs(ans-p)>abs(nea-p))ans=nea;
    }
    if(r>=2){
        ld o = func2(sum-p*(n-2));
        ld nea=(sum-o)/(n-2);
        debugv(abs(p-nea));
        if(abs(ans-p)>abs(nea-p))ans=nea;
    }
    if(r>=3){
        ld o = func3(sum-p*(n-3));
        ld nea=(sum-o)/(n-3);
        debugv(abs(p-nea));
        if(abs(ans-p)>abs(nea-p))ans=nea;
    }

    if(r>=4){
        ld o = func4(sum-p*(n-4));
        ld nea=(sum-o)/(n-4);
        debugv(abs(p-nea));
        if(abs(ans-p)>abs(nea-p))ans=nea;
    }

    cout<<fixed<<setprecision(10)<<abs(ans-p)<<'\n';
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