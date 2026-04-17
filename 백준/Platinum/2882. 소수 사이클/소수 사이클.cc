#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a * (b / gcd(a, b)); }
#define rep(i,a,b) for(LL i = a; i < b; i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()

bool eratos[8000000];
ll prime[500005];
ll n,k,a;

ll find_a_location(ll x,ll p){
    if(!x) return p%n;
    else if(x<=p%(n-1)) x= (x+n-1)%n;
    return (((x-p/(n-1))%n)+n)%n;
}

ll re_find_a_location(ll x,ll p){
    if(x==p%n) return 0;
    else{
        x=(((x+p/(n-1))%n)+n)%n;
        if(x<=p%(n-1))return (x+1)%n;
        return x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j,pr=0;
    cin>>n>>k>>a;
    for(i=2;i<8000000;i++){
        if(!eratos[i]){
            prime[pr++]=i;
            for(j=i;j<8000000;j+=i){
                eratos[j]=1;
            }
            if(k==pr)break;
        }
    }
    a--;
    for(i=0;i<k;i++)
    {a=find_a_location(a,prime[i]);}
    ll neighbor=(a+1)%n;
    for(i=0;i<k;i++)neighbor=re_find_a_location(neighbor,prime[k-i-1]);
    cout<<neighbor+1<<' ';
    neighbor=(a-1+n)%n;
    for(i=0;i<k;i++)neighbor=re_find_a_location(neighbor,prime[k-i-1]);
    cout<<neighbor+1<<' ';


    return 0;
}
