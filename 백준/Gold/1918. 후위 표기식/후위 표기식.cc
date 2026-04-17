#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string str;
    cin>>str;
    map<char,int>op;
    op['*']=1;
    op['/']=1;
    op['+']=2;
    op['-']=2;
    op['(']=3;
    op[')']=3;
    stack<char>stk;
    for(char t:str){
        if(t<='Z'&&t>='A'){
            cout<<t;
        }
        else if(t=='('){
            stk.push(t);
        }
        else if(t==')'){
            while(stk.top()!='('){
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            while(!stk.empty()&&op[stk.top()]<=op[t]){
                if(stk.top()!='('&&stk.top()!=')')cout<<stk.top();
                stk.pop();
            }
            stk.push(t);
        }
    }
    while(!stk.empty()){
        if(stk.top()!='('&&stk.top()!=')')cout<<stk.top();
        stk.pop();
    }

    return 0;
}
