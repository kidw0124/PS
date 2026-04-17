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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,k;
queue<ll> que;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push"){
            cin>>k;
            que.push(k);
        }
        else if(s=="size"){
            cout<<que.size()<<'\n';
        }
        else if(s=="empty"){
            cout<<que.empty()<<'\n';
        }
        else if(que.empty()){
            cout<<"-1\n";
        }
        else if(s=="back"){
            cout<<que.back()<<'\n';
        }
        else{
            cout<<que.front()<<'\n';
            if(s=="pop")que.pop();
        }
    }

    return 0;
}
