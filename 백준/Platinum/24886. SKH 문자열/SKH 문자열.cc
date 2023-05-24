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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	string str;
	map<string,ll>mp;
	mp["S"]=0;
	mp["SK"]=0;
	mp["SH"]=0;
	mp["K"]=0;
	mp["KH"]=0;
	mp["H"]=0;
	ll ans=0,n,p,q,r;
	cin>>n>>p>>q>>r;
	cin>>str;
	for(i=0;i<str.size();i++){
		switch(str[i]){
		case 'S':
			if(i==str.size()-1){
				mp["S"]++;
				break;
			}
			switch(str[i+1]){
			case'S':
				mp["S"]++;
				break;
			case'H':
				mp["SH"]++;
				i++;
				break;
			default:
				if(i==str.size()-2){
					mp["SK"]++;
					i++;
					break;
				}
				if(str[i+2]=='H'){
					ans++;
					i+=2;
					break;
				}
				else{
					mp["SK"]++;
					i++;
					break;
				}
			}
			break;
		case'K':
			if(i==str.size()-1){
				mp["K"]++;
				break;
			}
			switch(str[i+1]){
			case 'S':case'K':
				mp["K"]++;
				break;
			default:
				mp["KH"]++;
				i++;
				break;
			}
			break;
		case 'H':
			mp["H"]++;
			break;
		}
	}
	ans+=min(p,mp["KH"]);
	p-=min(p,mp["KH"]);
	ans+=min(q,mp["SH"]);
	q-=min(q,mp["SH"]);
	ans+=min(r,mp["SK"]);
	r-=min(r,mp["SK"]);
	ll x;
	while(true){
		if(min({p,q,r})==p){
			if(mp["S"]>0&&min({q,r})>0){
				mp["S"]--,q--,r--;
			}
			else if(min({q,r})==q&&p>0){
				if(mp["K"]>0){
					mp["K"]--,p--,r--;
				}
				else if(mp["H"]>0){
					mp["H"]--,p--,q--;
				}
				else break;
			}
			else if(min({q,r}
						)==r&&p>0){
				if(mp["H"]>0){
					mp["H"]--,p--,q--;
				}
				else if(mp["K"]>0){
					mp["K"]--,p--,r--;
				}
				else break;
			}
			else break;
		}
		else if(min({p,q,r})==q){
			if(mp["K"]>0&&min({p,r})>0){
				mp["K"]--,p--,r--;
			}
			else if(min({p,r})==p&&q>0){
				if(mp["S"]>0){
					mp["S"]--,q--,r--;
				}
				else if(mp["H"]>0){
					mp["H"]--,p--,q--;
				}
				else break;
			}
			else if(min({p,r})==r&&q>0){
				if(mp["H"]>0){
					mp["H"]--,p--,q--;
				}
				else if(mp["S"]>0){
					mp["S"]--,r--,q--;
				}
				else break;
			}
			else break;
		}
		else{
			if(mp["H"]>0&&min({q,p})>0){
				mp["H"]--,p--,q--;
			}
			else if(min({p,q})==p&&r>0){
				if(mp["S"]>0){
					mp["S"]--,q--,r--;
				}
				else if(mp["K"]>0){
					mp["K"]--,p--,r--;
				}
				else break;
			}
			else if(min({p,q})==q&&r>0){
				if(mp["K"]>0){
					mp["K"]--,p--,r--;
				}
				else if(mp["S"]>0){
					mp["S"]--,r--,q--;
				}
				else break;
			}
			else break;
		}
		ans++;
	}
	ans+=min({p,q,r});
	cout<<ans;
	return 0;
}
