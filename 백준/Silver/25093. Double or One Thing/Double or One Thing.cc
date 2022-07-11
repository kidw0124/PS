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
ll Answer;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer=0;
        cout << "Case #" << test_case+1 << ": ";
        string str;
        cin>>str;
        j=0;
        for(i=0;i<str.size();i++){
			j++;
			if(i<str.size()-1&&str[i]!=str[i+1]&&(str[i]<str[i+1])){
				while(j--)cout<<str[i];
				j=0;
			}
			else if(i<str.size()-1&&str[i]!=str[i+1])j=0;
			cout<<str[i];
        }
        cout<<"\n";
    }

    return 0;//Your program should return 0 on normal termination.
}
