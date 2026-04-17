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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string str;
    while(getline(cin,str),str!="#"){
        stack<char> stk;
        for(i=0;i<str.size();i++){
            if(str[i]=='('||str[i]=='{'||str[i]=='[')stk.push(str[i]);
            else{
                switch(str[i]){
                case ')':
                    if(stk.empty()||stk.top()!='(')goto abc;
                    stk.pop();
                    break;
                case '}':
                    if(stk.empty()||stk.top()!='{')goto abc;
                    stk.pop();
                    break;
                case ']':
                    if(stk.empty()||stk.top()!='[')goto abc;
                    stk.pop();
                    break;
                }
            }
        }
        if(stk.empty()){
            cout<<"Legal\n";
            continue;
        }
        abc:;
        cout<<"Illegal\n";
    }

    return 0;
}
