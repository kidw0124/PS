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

void solve(ll testcase) {
    ll i,j,k;
    ll w,h;
    cin>>w>>h;
    ll now=0,x=1,qq=0;
    vector<ll>arr(w);
    iota(all(arr),1);
    random_device rd;
    mt19937 gen(rd());
    shuffle(arr.begin(),arr.end(),gen);
    for(i=0;i<w;i++){
        ll q=now+1,s=now+1,e=h;
        cout<<"? "<<arr[i]<<' '<<q<<'\n';
        cout.flush();
        qq++;
        string str;
        cin>>str;
        if(str=="building"){
            s=q;
            now=q;
            x=arr[i];
        }
        else continue;
        if(qq==12000){
            cout<<"! "<<x<<' '<<now<<'\n';
            cout.flush();
            return;
        }
        if(now==h){
            cout<<"! "<<x<<' '<<now<<'\n';
            cout.flush();
            return;

        }
        while(s<e){
            ll mid=(s+e+1)>>1;
            q=mid;
            cout<<"? "<<arr[i]<<' '<<q<<'\n';
            cout.flush();
            qq++;
            cin>>str;
            if(str=="building"){
                s=mid;
                x=arr[i];
            }
            else e=mid-1;

            if(qq==12000){
                cout<<"! "<<x<<' '<<now<<'\n';
                cout.flush();
                return;
            }
        }
        now=s;
        if(now==h){
            cout<<"! "<<x<<' '<<now<<'\n';
            cout.flush();
            return;

        }
    }
    cout<<"! "<<x<<' '<<now<<'\n';
    cout.flush();
}

int main()
{
//    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}