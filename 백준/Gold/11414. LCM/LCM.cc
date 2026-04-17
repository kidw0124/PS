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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    LL a,b;
    cin>>a>>b;
    if(a<b)swap(a,b);
    LL c=a-b;
    LL M=1e19;
    LL t=0;
    if(a==b) return (printf("1")*0);
    for(i=1;i*i<=c;i++){
        if(c%i) continue;
        else{
            LL N=i-a%i;
            LL m=(a+N)*((b+N)/i);
            if(m<M){
                M=m;
                t=N;
            }
            else if(m==M){
                t=min(t,N);
            }
            j=c/i;

            N=j-a%j;
            m=(a+N)*((b+N)/j);
            if(m<M){
                M=m;
                t=N;
            }
            else if(m==M){
                t=min(t,N);
            }
        }
    }

    cout<<t;


    return 0;
}
