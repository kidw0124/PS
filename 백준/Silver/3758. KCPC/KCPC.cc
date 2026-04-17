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

int t, n, k, id, m, a, b, c;
int g[101][101];
struct student{
    int id,total, cnt, time;
    bool operator<(student r){
        return total==r.total?cnt==r.cnt?time<r.time:cnt<r.cnt:total>r.total;
    }
} s[110];
bool cmp(student a, student b) {
    if (a.total == b.total) {
        if (a.cnt == b.cnt)
            return a.time < b.time;
        return a.cnt < b.cnt;
    }
    return a.total > b.total;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    cin>>t;
    while(t--){
        int res;
        memset(s, 0, sizeof(s));
        memset(g, 0, sizeof(g));
        cin>>n>>k>>id>>m;
        for (int i = 0; i < n; i++)s[i].id = i + 1;
        for (int i = 0; i < m; i++) {
            cin>>a>>b>>c;
            g[a][b] = max(g[a][b], c);
            s[a - 1].cnt++;
            s[a - 1].time = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++)
                s[i - 1].total += g[i][j];
        }
        sort(s, s + n);
        for (int i = 0; i < n; i++) {
            if (s[i].id == id)
                res = i + 1;
        }
        cout<<res<<'\n';
    }

    return 0;
}
