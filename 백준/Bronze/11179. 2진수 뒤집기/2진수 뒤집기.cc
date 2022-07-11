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
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;

    //10진수 -> 8진수
    stringstream ss;
    ss<<oct<<n;
    string str;
    ss>>str;

    //8진수 -> 2진수 뒤집어진거
    string ans;
    if(str=="0")str="0";
    else{
        for(auto k:str){
            ans+=vector<string>({"000","001","010","011",
                                "100","101","110","111"})[k-'0'];
        }
        str=ans.substr(ans.find('1'));
    }

    //뒤집기
    reverse(all(str));

    //2진수 -> 8진수
    ans="";
    reverse(all(str));
    str+="00";
    for(i=0;i<str.size()-2;i+=3){
        ans+=[&](const string&ostr){
            ll ret=0;
            for(j=0;j<3;j++){
                ret|=(ostr[j]-'0')<<j;
            }
            return ret+'0';
        }(str.substr(i,3));
    }
    reverse(all(ans));

    //출력
    ss.clear();
    ss<<ans;
    ss>>oct>>n;
    cout<<n;

    return 0;
}
