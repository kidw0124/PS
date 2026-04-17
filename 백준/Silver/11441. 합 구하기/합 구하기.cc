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
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a * (b / gcd(a, b)); }
#define rep(i,a,b) for(LL i = a; i < b; i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()

LL n,m;
vector<LL> arr;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    cin>>n;
    rep(i,0,n){
        LL t;
        cin>>t;
        if(i)arr.pb(arr[i-1]+t);
        else arr.pb(t);
    }
    cin>>m;
    rep(i,0,m){
        LL t,tt;
        cin>>t>>tt;
        cout<<arr[tt-1]-((t==1)?0:arr[t-2])<<"\n";
    }


    return 0;
}
