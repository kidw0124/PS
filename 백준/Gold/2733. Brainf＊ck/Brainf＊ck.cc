#include<bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    setup();
    ll i,j;
    ll n,t;
    cin>>t;
    string str;
    getline(cin,str);
    for(int testcase = 1; testcase <= t; testcase++){
        cout<<"PROGRAM #"<<testcase<<":\n";
        int p=0;
        string program;
        vector<unsigned char>arr(32768);
        while(getline(cin,str),str!="end"){
            for(i=0;i<str.size();i++){
                if(str[i]=='%')break;
                switch (str[i]) {
                    case '<':
                    case '>':
                    case '+':
                    case '-':
                    case '.':
                    case '[':
                    case ']':
                        program += str[i];
                }
            }
        }
        vector<ll>par(program.size());
        debug<<program<<'\n';
        stack<ll>stk;
        bool b=1;
        for(i=0;i<program.size();i++){
            if(program[i]=='['){
                stk.push(i);
            }
            else if(program[i]==']'){
                if(stk.size()==0)b=0;
                else{
                    par[i]=stk.top();
                    par[stk.top()]=i;
                    stk.pop();
                }
            }
        }
        if(stk.size()!=0)b=0;
        if(!b){
            cout<<"COMPILE ERROR\n";
        }
        else{
            for(i=0;i<program.size();i++){
                //debug<<arr[p]<<'\n';
                switch (program[i]) {
                    case'>':
                        p=(p+1)%32768;
                        break;
                    case'<':
                        p=(p+32767)%32768;
                        break;
                    case'+':
                        arr[p]++;
                        break;
                    case'-':
                        arr[p]--;
                        break;
                    case'.':
                        cout<<arr[p];
                        break;
                    case'[':
                        //for(j=0;j<10;j++)debug<<arr[j];debug<<'\n';
                        if(arr[p]==0){
                            i=par[i];
                        }
                        break;
                    case']':
                        if(arr[p]!=0){
                            i=par[i];
                        }
                        break;
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}
