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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    int N;
    cin>>N;
    vector<LL> ph(N);
    for(i=0;i<N;i++){
        cin>>ph[i];
    }

    sort(ph.begin(),ph.end());
    i=0,j=N-1;
    LL ans=9999999999;
    pll ans_p;
    while(i<j){
        LL t=ph[i]+ph[j];
        if(abs(t)<ans){
            ans=abs(t);
            ans_p=make_pair(ph[i],ph[j]);
        }
        if(t<0)i++;
        else j--;
    }
    cout<<ans_p.first<<' '<<ans_p.second;


    return 0;
}
