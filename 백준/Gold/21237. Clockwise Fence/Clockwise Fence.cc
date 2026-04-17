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

vector<pii>point;

string fuck(){
    int a=0;
    for(int i=0;i<point.size();i++){
        a+=point[i].first*point[(i+1)%point.size()].second;
        a-=point[i].second*point[(i+1)%point.size()].first;
    }

    return a>0?"CCW":"CW";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string s;
    int n;
    cin>>n;
    for(i=0;i<n;i++){
        point.clear();
        cin>>s;
        int x=0,y=0;
        for(j=0;j<s.size();j++){
            if(s[j]=='W')x--;
            if(s[j]=='E')x++;
            if(s[j]=='N')y++;
            if(s[j]=='S')y--;
            point.pb(make_pair(x,y));
        }
        cout<<fuck()<<'\n';
    }

    return 0;
}
