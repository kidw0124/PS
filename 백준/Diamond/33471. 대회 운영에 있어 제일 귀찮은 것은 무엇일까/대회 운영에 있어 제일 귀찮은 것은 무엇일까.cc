#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
//#include<atcoder/all>
//using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
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

struct fenwick {
    vector<int> tree;

    fenwick(int n) {
        tree.resize(n + 1);
    }

    void update(int i, int diff) {
        i++;
        while (i < tree.size()) {
            tree[i] += diff;
            i += (i & -i);
        }
    }
    void reset(){
        fill(all(tree),0);
    }
    int sum(int i) {
        i++;
        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & -i);
        }
        return ans;
    }
};

void solve() {
    int i,j;
    string str;
    cin>>str;
    int n = str.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<vector<int>>rz(n+1);
    for (i = 0; i < n; i++) {
        rz[z[i]].push_back(i);
    }
    int ans_idx=0;
    pair<int,int> ans={n,n};
    fenwick fen(n);
    auto func=[&](int l)->pair<int,int>{
        int now=l, ret=l, tot=l+1;
        while(now<n){
            int st=now,en=n-1;
            int tsum=fen.sum(now-1);
            if (fen.sum(n-1)==tsum){
                ret+=n-now;
                tot+=n-now;
                now=n;
            }
            else {
                while (st < en) {
                    int mid = (st + en) >> 1;
                    if (fen.sum(mid) == tsum) {
                        st = mid + 1;
                    } else {
                        en = mid;
                    }
                }
                ret += st - now;
                tot += st - now + 1;
                now = st + l;
            }
        }
        return {ret,tot};
    };
    auto func2=[&](int l)->string{
        for(i=0;i<n;i++) {
            if(z[i]>=l) fen.update(i,1);
        }
        int now=l;
        string ret(l,'1');
        ret+='2';
        while(now<n){
            int st=now,en=n-1;
            int tsum=fen.sum(now-1);
            if (fen.sum(n-1)==tsum){
                ret+=string(n-now,'1');
                break;
            }
            while(st<en){
                int mid=(st+en)>>1;
                if (fen.sum(mid)==tsum){
                    st=mid+1;
                }else{
                    en=mid;
                }
            }
            ret+=string(st-now,'1');
            ret+='2';
            now=st+l;
        }
        return ret;
    };
    for(i=n;i>0;i--){
        for(auto x:rz[i]){
            fen.update(x,1);
        }
        auto ret=func(i);
        if (ret<ans){
            ans=ret;
            ans_idx=i;
        }
    }
    fen.reset();
    if(ans.first==n && ans.second==n){
        cout<<n<<' '<<n<<'\n';
        cout<<string(n,'1')<<'\n';
    }
    else {
        cout << ans.first << ' ' << ans.second << '\n';
        cout << func2(ans_idx) << '\n';
    }
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