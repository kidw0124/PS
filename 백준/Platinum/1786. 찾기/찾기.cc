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
string t,p;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    getline(cin,t);
    getline(cin,p);
    int n=t.size(),x=p.size();
    vector<int>kmp(x,0);
    j=0;
    for(i=1;i<x;i++) {
		while(j>0&&p[i]!= p[j])
			j=kmp[j-1];
		if(p[i]==p[j])
            kmp[i]=++j;
	}
    vi ans;
    j=0;
    for(i=0;i<n;i++){
        while(j>0&&t[i]!=p[j]){
            j=kmp[j-1];
        }
        if(t[i]==p[j]){
            j++;
            if(j==x){
                ans.pb(i-x+2);
                j=kmp[j-1];
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(int i:ans)cout<<i<<' ';
    return 0;
}
