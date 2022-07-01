#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <iostream>
#include <tuple>
#include <string>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
ll MOD = 1000000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a * (b / gcd(a, b)); }
bool OOB(int x, int y, int N, int M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << a << ' '
#define pf2(a,b) cout << a << ' ' << b << ' '
#define pf3(a,b,c) cout << a << ' ' << b << ' '<< c << ' '
#define pf4(a,b,c,d) cout << a << ' ' << b << ' '<< c << ' '<< d << ' '
#define pf5(a,b,c,d,e) cout << a << ' ' << b << ' '<< c << ' '<< d << ' '<< e << ' '
#define pf6(a,b,c,d,e,f) cout << a << ' ' << b << ' '<< c << ' '<< d << ' '<< e << ' ' << f << ' '
#define pf1l(a) cout << a << '\n'
#define pf2l(a,b) cout << a << ' ' << b << '\n'
#define pf3l(a,b,c) cout << a << ' ' << b << ' '<< c << '\n'
#define pf4l(a,b,c,d) cout << a << ' ' << b << ' '<< c << ' '<< d << '\n'
#define pf5l(a,b,c,d,e) cout << a << ' ' << b << ' '<< c << ' '<< d << ' '<< e << '\n'
#define pf6l(a,b,c,d,e,f) cout << a << ' ' << b << ' '<< c << ' '<< d << ' '<< e << ' ' << f << '\n'
const ll MX=(ll)1e6;
int mobius[(ll)1e6+1];
// N 이하의 square free number의 수
ll solve(ll N){
  ll ret = 0;
  for(ll i = 1; i*i <= N; i++) ret += mobius[i] * (N/(i*i));
  return N-ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
  ll K;
  sf1(K);
  fill(mobius+1,mobius+MX+1,1);
  for(ll i = 2; i*i <= MX; i++){
    if(mobius[i]==1){
      for(ll j = i; j <= MX; j+=i) mobius[j] *= -i;
      for(ll j = i*i; j <= MX; j+=i*i) mobius[j] = 0;
    }
  }
  for(int i = 2; i <= MX; i++){
    if(mobius[i] == i) mobius[i] = 1;
    else if(mobius[i] == -i) mobius[i] = -1;
    else if(mobius[i] < 0) mobius[i] = 1;
    else if(mobius[i] > 0) mobius[i] = -1;
  }
  ll st = 1;
  ll en = 200'000'000'000;
  while(st<en){
    ll mid = (st+en)>>1;
    ll val = solve(mid);
    if(val > K) en = mid-1;
    else if(val == K) en = mid;
    else st = mid+1;
  }
  pf1l(st);

}
