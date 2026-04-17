#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
vector<ll>fibo;

    vector<ll>grundy(3'000'001);
ll find_g(vector<ll>&st){
    for(ll i=0;;i++){
    	if(find(all(st),i)==st.end())return i;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    fibo.push_back(1);
    fibo.push_back(2);
    while(*fibo.rbegin()<2'000'000){
        fibo.push_back(*fibo.rbegin()+(*(fibo.rbegin()+1)));
    }
    cin>>n;
    for(i=1;i<3'000'001;i++){
        int g=0;
        for(j=0;j<fibo.size();j++){
            if(fibo[j]>i)break;
            else g|=(1<<grundy[i-fibo[j]]);
        }
        g=~g;
        grundy[i]=__builtin_ctz(g);
//        cout<<i<<' '<<grundy[i]<<'\n';
    }
    ll ans=0;
    for(i=0;i<n;i++){
        cin>>j;
        ans^=grundy[j];
    }
    ans?cout<<"koosaga":cout<<"cubelover";
    return 0;
}
