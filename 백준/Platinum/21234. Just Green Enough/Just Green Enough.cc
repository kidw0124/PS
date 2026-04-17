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
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll POW(ll a, ll b, ll rem) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}
ll subdp[505][505], resultdp[505][505], n, a[505][505], i, j, k, assist, sumofzeroandone, sumofone;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin>>a[i][j];
            if (a[i][j] < 100)a[i][j] = -1;
            else if (a[i][j] == 100)a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (a[i][j] != -1)subdp[i][j] = subdp[i - 1][j] + 1;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            assist = subdp[i][j];
            resultdp[i][j] = subdp[i][j];
            for (k = j - 1; k >= 1; k--) {
                if (assist > subdp[i][k])assist = subdp[i][k];
                resultdp[i][j] += assist;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            sumofzeroandone += resultdp[i][j];
            subdp[i][j] = 0;
            resultdp[i][j] = 0;
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (a[i][j] == 1)subdp[i][j] = subdp[i - 1][j] + 1;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            assist = subdp[i][j];
            resultdp[i][j] = subdp[i][j];
            for (k = j - 1; k >= 1; k--) {
                if (assist > subdp[i][k])assist = subdp[i][k];
                resultdp[i][j] += assist;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            sumofone += resultdp[i][j];
        }
    }

    cout<<sumofzeroandone-sumofone;


    return 0;
}
