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
LL N,K;
vector<long double> arr,brr;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    cin>>N>>K;
    rep(i,0,N){
        long double t;
        cin>>t;
        brr.pb(t);
    }
    sort(brr.begin(),brr.end());
    rep(i,0,N){
        if(i>=K&&i<N-K)arr.pb(brr[i]);
    }
    LL l=arr.size();
    long double m=0,n;
    rep(i,0,l){
        m+=arr[i];
    }
    m+=1e-9;
    n=m+K*(arr[0]+arr[l-1]);
    cout<<fixed;
    cout.precision(2);
    cout<<m/(long double)(N-2*K)<<endl<<n/(long double)N;
    return 0;
}
