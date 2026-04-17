#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
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

const ll mod = 1e9+7;

void setup()
{
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
    ll i, j;


}

const ld PI_2 = acos((ld)0);
const ld eps = 1e-17;

void solve(ll testcase){
    ll w,h;
    ll n,d;
    ll i,j,k, dd;
    cin >> w >> h;
    cin >> n >> d;
    cout<<fixed<<setprecision(12);
    vector<ll>arr(n+1),prr(n+1);
    for(i=1;i<=n;i++) cin >> arr[i];
    for(i=1;i<=n;i++) cin >> prr[i];
    for(i=0;i<=n;i++){
        dd = i;
        if(arr[i]>d){
            break;
        }
    }
    ld st = 0, en = PI_2;
    while(en-st>eps){
        ld now = 0;
        ld mid = (st+en)/2;
        ld theta = mid;
        bool isup = true;
        for(i=1;i<=dd;i++){
            ld y = (arr[i] - arr[i-1]);
            ld x = w-now;
            ld tan_theta = tan(theta);
            ld y2 = x*tan_theta;
            if(y2<y){
                if(arr[i-1]+y2>d){
                    isup = true;
                    break;
                }
                else{
                    isup = false;
                    break;
                }
            }
            else{
                ld cot_theta = 1/tan_theta;
                ld x2 = y*cot_theta;
                now += x2;
            }
            if(i<dd) {
                ld sin_theta_inv = cos(theta);
                sin_theta_inv *= prr[i];
                sin_theta_inv /= prr[i+1];
                if(sin_theta_inv>1){
                    isup = false;
                    break;
                }
                theta = acos(sin_theta_inv);
            }
        }
        if(isup){
            en = mid;
        }
        else{
            st = mid;
        }
    }
    ld ans = 0;
    ld theta = st;
    ld nowx = 0;
    for(i=1;i<=dd;i++){
        if(arr[i]>d){
            if(arr[i-1]==d){
                ans += (w-nowx) * prr[i];
            }
            else ans += (d-arr[i-1])/sin(theta) * prr[i];
        }
        else ans += (arr[i]-arr[i-1])/sin(theta) * prr[i];
        nowx += (arr[i]-arr[i-1])/tan(theta);
        debug << "theta : " << theta << " ans : " << ans << endl;
        ld sin_theta_inv = cos(theta);
        debug << "sin_theta_inv : " << sin_theta_inv << endl;
        sin_theta_inv *= prr[i];
        debug << "sin_theta_inv : " << sin_theta_inv << endl;
        sin_theta_inv /= prr[i+1];
        debug << "sin_theta_inv : " << sin_theta_inv << endl;
        if(sin_theta_inv>1){
            sin_theta_inv = 1;
        }
        theta = acos(sin_theta_inv);
        debug << "theta : " << theta << " ans : " << ans << endl;
    }
    debug<<fixed<<setprecision(10) << ans << endl;
    for(i=(arr[dd-1]==d?dd:dd+1);i<=n;i++){
        ld ratio = (ld)prr[i]/prr[1];
        ld theta = acos(ratio);
        ld tmp = 0;
        ld nowx = 0;
        debug << ratio << " " << theta << endl;
        for(j=1;j<i;j++){
            tmp += (arr[j]-arr[j-1])/sin(theta) * prr[j];
            nowx += (arr[j]-arr[j-1])/tan(theta);

            ld sin_theta_inv = cos(theta);
            sin_theta_inv *= prr[j];
            sin_theta_inv /= prr[j+1];
            if(sin_theta_inv>1){
                sin_theta_inv = 1;
            }
            theta = acos(sin_theta_inv);
        }
        ld revx = 0;
        ld revratio = (ld)prr[i]/prr[dd];
        ld revtheta = acos(revratio);
        for(j=dd;j<i;j++){
            if(j==dd){
                tmp += (arr[j]-d)/sin(revtheta) * prr[j];
                revx += (arr[j]-d)/tan(revtheta);
            }
            else{
                tmp += (arr[j]-arr[j-1])/sin(revtheta) * prr[j];
                revx += (arr[j]-arr[j-1])/tan(revtheta);
            }
            ld sin_theta_inv = cos(revtheta);
            sin_theta_inv *= prr[j];
            sin_theta_inv /= prr[j+1];
            if(sin_theta_inv>1){
                sin_theta_inv = 1;
            }
            revtheta = acos(sin_theta_inv);
        }
        if(revx + nowx < w){
            tmp += (w-revx-nowx) * prr[i];
            debug << "revx : " << revx << " nowx : " << nowx << " w : " << w << endl;
            debug << "tmp : " << tmp << endl;
            ans = min(ans,tmp);
        }
        else{
            debug << "revx : " << revx << " nowx : " << nowx << " w : " << w << endl;
            debug << "tmp : " << tmp << endl;
        }
    }
    cout<<fixed<<setprecision(10) << ans;
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}
