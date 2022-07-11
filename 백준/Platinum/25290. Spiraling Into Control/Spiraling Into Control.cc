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
        ll n,k;
        cin>>n>>k;
        Answer=0;
        cout << "Case #" << test_case+1 << ": ";
        if(k%2!=0||k<n-1){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        else{
            ll d=n*n-1-k;
            deque<pll>arr;
            for(i=n-1;i>=2;i-=2){
                if(d>=4*i-2){
                    d-=4*i-2;
                    arr.push_back({i,1});
                }
                else if(d>=4*i-4){
                    d-=4*i-4;
                    arr.push_back({i,2});
                }
                else if(d>=4*i-6){
                    d-=4*i-6;
                    arr.push_back({i,3});
                }
                else if(d>=4*i-8&&d>0){
                    d-=4*i-8;
                    arr.push_back({i,4});
                }
            }
            cout<<arr.size()<<'\n';
            ll x=1;
            for(i=n-1;i>=2;i-=2){
                if(!arr.empty()&&arr.front().first==i){
                    cout<<x+arr.front().second*i-i+1<<' '<<x+arr.front().second*i-i+2+4*i-2*arr.front().second<<'\n';;
                    arr.pop_front();
                }
                x+=4*i;
            }
        }


    }

    return 0;//Your program should return 0 on normal termination.
}
