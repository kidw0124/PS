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

vector<vector<pll>>arr(26);
ll n,m;

string strans;

void cntcnt(pll st, pll en){
	ll ret=0;
	if(st.first<en.first){
		ret+=en.first-st.first;
		for(ll i=0;i<en.first-st.first;i++){
			strans+='D';
		}
	}
	else{
		ret-=en.first-st.first;
		for(ll i=0;i<st.first-en.first;i++){
			strans+='U';
		}
	}
	if(st.second<en.second){
		ret+=en.second-st.second;
		for(ll i=0;i<en.second-st.second;i++){
			strans+='R';
		}
	}
	else{
		ret-=en.second-st.second;
		for(ll i=0;i<st.second-en.second;i++){
			strans+='L';
		}
	}
	ret++;
	strans+='P';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	cin>>n>>m>>j;
	vector<string>aaa(n);
	for(i=0;i<n;i++){
		cin>>aaa[i];
		for(j=0;j<m;j++){
			arr[aaa[i][j]-'a'].push_back({i,j});
		}
	}
	string str;
	cin>>str;
	ll ans=n*m;
	vector<ll>brr(26);
	for(i=0;i<str.size();i++){
		brr[str[i]-'a']++;
	}
	for(i=0;i<26;i++){
		if(brr[i]){
			ans=min((ll)arr[i].size()/brr[i],ans);
		}
	}
	fill(all(brr),0);
	pll now={0,0};
	for(i=0;i<ans;i++){
		for(auto k:str){
			cntcnt(now,arr[k-'a'][brr[k-'a']]);
			now=arr[k-'a'][brr[k-'a']++];
		}
	}
	cntcnt(now,{n-1,m-1});
	strans.pop_back();
	cout<<ans<<' '<<strans.size()<<'\n'<<strans;


	return 0;
}
