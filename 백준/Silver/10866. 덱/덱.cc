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
deque<ll> que;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push_front"){
            cin>>k;
            que.push_front(k);
        }
        else if(s=="push_back"){
            cin>>k;
            que.push_back(k);
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
        else if(s=="front"){
            cout<<que.front()<<'\n';
        }
        else if(s=="pop_back"){
            cout<<que.back()<<'\n';
            que.pop_back();
        }
        else if(s=="pop_front"){
            cout<<que.front()<<'\n';
            que.pop_front();
        }
    }

    return 0;
}
