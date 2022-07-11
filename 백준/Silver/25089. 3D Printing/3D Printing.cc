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
        vector<vector<ll>>arr(4,vector<ll>(3));
        for(i=0;i<3;i++){
			for(j=0;j<4;j++)cin>>arr[j][i];
        }
        for(i=0;i<4;i++){
			sort(all(arr[i]));
        }
        if(arr[0][0]+arr[1][0]+arr[2][0]+arr[3][0]<1000000)cout<<"IMPOSSIBLE\n";
        else{
			ll tot=1000000;
			for(i=0;i<4;i++){
				if(tot<=arr[i][0]){

					cout<<tot<<' ';
					tot=0;
				}
				else{
						cout<<arr[i][0]<<' ';
					tot-=arr[i][0];
				}
			}
			cout<<'\n';
        }
    }

    return 0;//Your program should return 0 on normal termination.
}
