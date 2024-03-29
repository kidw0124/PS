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
    cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    string str;
    getline(cin,str);
    deque<bool>org(27);
    org[0]=1;
    for(i=0;i<n;i++){
        stringstream ss;
        getline(cin,str);
        ss.str(str);
        vector<ll>arr;
        while(ss>>j){
            arr.push_back(j);
        }
        deque<bool>lorg(org.begin(),org.begin()+13);
        deque<bool>rorg(org.begin()+13,org.end());
        org.clear();
        for(j=0;j<arr.size();j++){
            if(j&1){
                for(ll k=0;k<arr[j];k++){
                    org.push_back(lorg[0]);
                    lorg.pop_front();
                }
            }
            else{
                for(ll k=0;k<arr[j];k++){
                    org.push_back(rorg[0]);
                    rorg.pop_front();
                }
            }
        }
    }
    cout<<find(all(org),1)-org.begin()+1;
    return 0;
}
